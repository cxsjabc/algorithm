#include <limits.h>
#include "size.h"
#include "common_local.h"

// the array should sync with SIZE_RATIO
const SizeRatio gSizeRatioArr[] = 
{
	{SIZE_RATIO_START, "ratio_start"},
	{SIZE_RATIO_4_3, "4:3"},
	{SIZE_RATIO_3_2, "3:2"},
	{SIZE_RATIO_5_3, "5:3"},
	{SIZE_RATIO_16_9, "16:9"},
	{SIZE_RATIO_UNKNOWN, "unknown ratio"},
	{SIZE_RATIO_MAX, "max ratio"},
};

const char *gSize4_3_Array[] = 
{
	"320x240",  "384x288",  "512x384", "640x480", "1280x960", "2560x1920",
};

const char *gVideoFixedSizes[9] = 
{
	"176x144",  "320x240",  "480x320", "640x480", "720x480",
	"1280x720", "1280x736", "1920x1080", "1920x1088",
};

int isSize16Aligned(int width, int height)
{
	return ((width & 0xF) == 0) && ((height & 0xF) == 0);
}

int isSizeAligned(int width, int height, int align)
{
	return ((width % align) == 0) && ((height % align) == 0);
}

int getSizeRatio(int w, int h)
{
	if(isSize4_3(w, h))
		return SIZE_RATIO_4_3;
	if(isSize3_2(w, h))
		return SIZE_RATIO_3_2;
	if(isSize5_3(w, h))
		return SIZE_RATIO_5_3;
	if(isSize16_9(w, h))
		return SIZE_RATIO_16_9;
	return SIZE_RATIO_UNKNOWN;
}

char *getSizeRatioStr(int w, int h)
{
	int sizeRatio = getSizeRatio(w, h);
    return gSizeRatioArr[sizeRatio].tip;	
}

int isSize4_3(int width, int height)
{
	if(width * 3 > INT_MAX - 1)
	{
		printf("width:%d is too big!\n", width);
		return 0;
	}	

	if(height * 3 > INT_MAX - 1)
	{
		printf("height:%d is too big!\n", height);
		return 0;
	}	

	if(width * 3 == height * 4)
		return 1;	
	return 0;
}

int isSize3_2(int width, int height)
{
	if(width * 2 > INT_MAX - 1)
	{
		printf("width:%d is too big!\n", width);
		return 0;
	}	

	if(height * 3 > INT_MAX - 1)
	{
		printf("height:%d is too big!\n", height);
		return 0;
	}	

	if(width * 2 == height * 3)
		return 1;	
	return 0;
}

int isSize5_3(int width, int height)
{
	if(width * 3 > INT_MAX - 1)
	{
		printf("width:%d is too big!\n", width);
		return 0;
	}	

	if(height * 5 > INT_MAX - 1)
	{
		printf("height:%d is too big!\n", height);
		return 0;
	}	

	if(width * 3 == height * 5)
		return 1;	
	return 0;
}

int isSize16_9(int width, int height)
{
	if(width * 9 > INT_MAX - 1)
	{
		printf("width:%d is too big!\n", width);
		return 0;
	}	

	if(height * 16 > INT_MAX - 1)
	{
		printf("height:%d is too big!\n", height);
		return 0;
	}	

	if(width * 9 == height * 16)
		return 1;	
	return 0;
}

int getNearestRatio(int w, int h)
{
	double ratio = ((double)w) / h;
	
	if(abs(ratio - (16.) / 9) <= 1e-7)
		return SIZE_RATIO_16_9;
	if(abs(ratio - (5.) / 3) <= 1e-7)
		return SIZE_RATIO_5_3;
	if(abs(ratio - (3.) / 2) <= 1e-7)
		return SIZE_RATIO_3_2;
	if(abs(ratio - (4.) / 3) <= 1e-7)
		return SIZE_RATIO_4_3;
	return SIZE_RATIO_4_3;
}

// the caller should free size_arr
int	generateSizeValues(int max_w, int max_h, char ***size_arr, int force_ratio)
{
	double ratio = ((double)max_w)/max_h;
	int ratioInt = getSizeRatio(max_w, max_h);
	int base;
	int i;
	int w, h;
	int ratioW, ratioH;
	int ret = 0;
	int new_ratio;
	
	*size_arr = NULL;

	if(force_ratio >= SIZE_RATIO_4_3 && force_ratio <= SIZE_RATIO_16_9)
	{
		printf("Force Ratio:%s\n", gSizeRatioArr[force_ratio].tip);
		ratioInt = force_ratio;
	}
		
label_switch_ratio:	
	switch(ratioInt)
	{
		case SIZE_RATIO_4_3:
			base = max_w/16/4;
			ratioW = 4;
			ratioH = 3;
		break;
		case SIZE_RATIO_3_2:
			base = max_w/16/3;
			ratioW = 3;
			ratioH = 2;
		break;
		case SIZE_RATIO_5_3:
			base = max_w/16/5;
			ratioW = 5;
			ratioH = 3;
		break;
		case SIZE_RATIO_16_9:
			base = max_w/16/16;
			ratioW = 16;
			ratioH = 9;
		break;
		default:
			ratioInt = getNearestRatio(max_w, max_h);
			printf("Ratio %f is not common, the neareast ratio:%s!\n", ratio, gSizeRatioArr[ratioInt].tip);
			goto label_switch_ratio;
		break;
	}
	*size_arr = (char **)malloc(base * sizeof(char *));
	if(!*size_arr)
		goto label_fail;
	memset(*size_arr, 0, base * sizeof(char *));
	
	for(i = 1; i <= base; ++i)
	{
		char *temp = (char *)malloc(128);
		if(!temp)
			goto label_fail;
		w = i * 16 * ratioW;
		h = i * 16 * ratioH;
		
		sprintf(temp, "\"%dx%d\"", w, h);
		(*size_arr)[i - 1] = temp;
		//printf("Add one size:%s\n", (*size_arr)[i - 1]);
		++ret;
	}
	return ret;
	
label_fail:
	for(i = 0; i < base; ++i)
		if((*size_arr)[i])
			free((*size_arr)[i]);
	if(*size_arr)
		free(*size_arr);
	return ret;
}

int getBiggestSize(char **arr, int cnt, int *w, int *h)
{
	int i = 0;
	int biggest = 0;
	*w = *h = 0;
	
	for(; i < cnt; ++i)
	{
		int temp_w, temp_h;
		parseStrToSize(arr[i], &temp_w, &temp_h);
		if(temp_w * temp_h > biggest)
		{
			biggest = temp_w * temp_h;
			*w = temp_w;
			*h = temp_h;
		}
	}
	
	return biggest;
}
