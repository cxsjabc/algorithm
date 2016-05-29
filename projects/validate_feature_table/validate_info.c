#include "validate_info.h"
#include "common.h"
#include "size.h"

int validate_align_xx(const char *s, int align)
{
	int w, h;
	int parse_ret;
	int ret = 0;
	
	parse_ret = parseStrToSize(s, &w, &h);
	if(parse_ret != 1)
		return 1;
	
	if(align == 16 && isSize16Aligned(w, h))
		ret = 0;
	else
		ret = isSizeAligned(w, h, align) ? 0 : 1;
		
	return ret;
}

int validate_none_blank(const char *s)
{
	int ret = 0;
	
	if(isStrContainChar(s, ' '))
		return 1;
	if(isStrContainChar(s, '\t'))
		return 1;
	if(isStrContainChar(s, '\n'))
		return 1;
	
	return ret;
}

int validate_video_size_must_included(const char **arr, int cnt, const void *data)
{
	int ret = 0;
	char *max_value = (char *)data;
	int i;
	int fixedVideoSize = sizeof(gVideoFixedSizes) / sizeof(gVideoFixedSizes[0]);
	int max_w, max_h;
	int fixedVideoSizeIndex = fixedVideoSize - 1;
	char temp_max_value[] = {"1920x1088"};
	
	if(max_value == NULL)
	{
		printf("Max Video Size is NULL, set to 1080P by default!\n");
		max_value = "1920x1088";
		max_value = temp_max_value;
	}
	
	dumpValuesArray(arr, cnt);
	
	ret = parseStrToSize(max_value, &max_w, &max_h);
	if(ret == 0)
	{
		printf("\tparse max video size: %s failed...\n", max_value);
		return 1;
	}
	for(i = fixedVideoSize - 1; i >= 0; --i)
	{
		int temp_w, temp_h;
		ret = parseStrToSize(gVideoFixedSizes[i], &temp_w, &temp_h);
		if(ret == 0)
		{
			printf("\tparse %s failed...\n", gVideoFixedSizes[i]);
			return 1;
		}
		if(max_w >= temp_w && max_h >= temp_h)
		{
			fixedVideoSizeIndex = i;
			break;
		}
	}
	printf("FixedVideoSize : %s\n", gVideoFixedSizes[fixedVideoSizeIndex]);
	ret = 0;
	for(i = 0; i <= fixedVideoSizeIndex; ++i)
	{
		if(!isStrInArr(gVideoFixedSizes[i], arr, cnt))
		{
			printf("\tSize:%s not included...\n", gVideoFixedSizes[i]);
			++ret;
		}
	}
	
	return ret;
}

int validate(const char *s, VALIDATE_INFO validate_info, const void *data)
{
	int ret = 0;
	int temp;
	char *max_value;
	
	switch(validate_info)
	{
		case VALIDATE_INFO_ALIGN_XX:
			temp = (int)*(int *)data;
			ret = validate_align_xx(s, temp);
		break;
		
		case VALIDATE_INFO_NONE_BLANK:
			ret = validate_none_blank(s);
		break;
		
		default:
		break;
	}
	
	return ret;
}

int validate_arrs(const char **arr, int cnt, VALIDATE_INFO validate_info, const void *data)
{
	int ret = 0;
	int i;
	
	if(validate_info == VALIDATE_INFO_VIDEO_SIZE_MUST_INCLUDED)
	{
		ret = validate_video_size_must_included(arr, cnt, data);
		return ret;	
	}
	
	for(i = 0; i < cnt; ++i)
	{
		if(validate(arr[i], validate_info, data) != 0)
		{
			printf("Validate %s Failed!\n", arr[i]);
			++ret;
		}
	}
	
	return ret;
}
