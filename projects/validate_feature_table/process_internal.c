#include <stdio.h>
#include <string.h>
#include "size.h"
#include "str_util.h"
#include "common.h"
#include "validate_info.h"

int process_picture_size(const char *buf, char *max_size)
{
	// max default value and default values is 4096
	char default_value[4096] = {0}, default_values[4096] = {0};
	int ret;
	ret = getKeyDefaultAndValues(buf, "MtkCameraParameters::KEY_PICTURE_SIZE", "ITEM_AS_DEFAULT_", "ITEM_AS_VALUES_", default_value, default_values);
	if(ret >= 2)		// at least include default_value and default_values
	{
		char **values_arr;
		int cnt;
		//printf("default_value:%s, default_values:%s\n", default_value, default_values);
		cnt = split_str(default_values, ",", &values_arr);
		if(cnt > 0)
		{
			int align_data = 16;
			int generateSizeCnt;
			char **genSizeValues;
			int w, h;
			int ratioInt;
			//dumpValuesArray(values_arr, cnt);
			
			trim_str_values(values_arr, cnt);
			fix_str_values_quoto(values_arr, cnt);
			trim_str_values(values_arr, cnt);
			//dumpValuesArray(values_arr, cnt);
			
			// validate align
			ret = validate_arrs(values_arr, cnt, VALIDATE_INFO_ALIGN_XX, &align_data);
			if(ret == 0)
				printf("validate align ok!\n");
			else
				printf("validate align Failed, failed items count:%d!\n", ret);
				
			// validate none blank
			ret = validate_arrs(values_arr, cnt, VALIDATE_INFO_NONE_BLANK, NULL);
			if(ret == 0)
				printf("validate none blank ok!\n");
			else
				printf("validate none blank Failed, failed items count:%d!\n", ret);
			
			// biggest size
			if(max_size == NULL)
				getBiggestSize(values_arr, cnt, &w, &h);
			else
				parseStrToSize(max_size, &w, &h);
			printf("BiggestSize: w:%d, h:%d\n", w, h);
			
			// generate values
			generateSizeCnt = generateSizeValues(w, h, &genSizeValues, 0);
		
			printf("generateSizeCnt:%d\n", generateSizeCnt);	
			dumpValuesArray(genSizeValues, generateSizeCnt);	
			freeValuesArray(genSizeValues, generateSizeCnt);
			
			// generate 4:3, 3:2, 5:3, 16:9 ratio picture sizes
			for(ratioInt = SIZE_RATIO_4_3; ratioInt <= SIZE_RATIO_16_9; ++ratioInt)
			{
				generateSizeCnt = generateSizeValues(w, h, &genSizeValues, ratioInt);
		
				printf("Force Ratio generateSizeCnt:%d\n", generateSizeCnt);	
				dumpValuesArray(genSizeValues, generateSizeCnt);	
				freeValuesArray(genSizeValues, generateSizeCnt);
			}
			
			freeValuesArray(values_arr, cnt);
		}
		else
		 ret = 1;
	}
	return ret;
}

int process_preview_size(const char *buf, char *max_size)
{
	// max default value and default values is 4096
	char default_value[4096] = {0}, default_values[4096] = {0};
	int ret;
	ret = getKeyDefaultAndValues(buf, "MtkCameraParameters::KEY_PREVIEW_SIZE", "ITEM_AS_DEFAULT_", "ITEM_AS_VALUES_", default_value, default_values);
	if(ret >= 2)		// at least include default_value and default_values
	{
		char **values_arr;
		int cnt;
		int generateSizeCnt;
		char **genSizeValues;
		int w, h;
		int ratioInt;
			
		//printf("default_value:%s, default_values:%s\n", default_value, default_values);
		cnt = split_str(default_values, ",", &values_arr);
		if(cnt > 0)
		{
			int align_data = 16;
			//dumpValuesArray(values_arr, cnt);
			
			trim_str_values(values_arr, cnt);
			fix_str_values_quoto(values_arr, cnt);
			trim_str_values(values_arr, cnt);
			//dumpValuesArray(values_arr, cnt);
			
			// validate align
			#if 0
			ret = validate_arrs(values_arr, cnt, VALIDATE_INFO_ALIGN_XX, &align_data);
			if(ret == 0)
				printf("validate align ok!\n");
			else
				printf("validate align Failed, failed items count:%d!\n", ret);
			#endif
			
			// validate none blank
			ret = validate_arrs(values_arr, cnt, VALIDATE_INFO_NONE_BLANK, NULL);
			if(ret == 0)
				printf("validate none blank ok!\n");
			else
				printf("validate none blank Failed, failed items count:%d!\n", ret);
			
			// biggest size
			if(max_size == NULL)
				getBiggestSize(values_arr, cnt, &w, &h);
			else
				parseStrToSize(max_size, &w, &h);
			printf("BiggestSize: w:%d, h:%d\n", w, h);
			
			// generate values
			generateSizeCnt = generateSizeValues(w, h, &genSizeValues, 0);
		
			printf("generateSizeCnt:%d\n", generateSizeCnt);	
			dumpValuesArray(genSizeValues, generateSizeCnt);	
			freeValuesArray(genSizeValues, generateSizeCnt);
			
			// generate 4:3, 3:2, 5:3, 16:9 ratio picture sizes
			for(ratioInt = SIZE_RATIO_4_3; ratioInt <= SIZE_RATIO_16_9; ++ratioInt)
			{
				generateSizeCnt = generateSizeValues(w, h, &genSizeValues, ratioInt);
		
				printf("Force Ratio generateSizeCnt:%d\n", generateSizeCnt);	
				dumpValuesArray(genSizeValues, generateSizeCnt);	
				freeValuesArray(genSizeValues, generateSizeCnt);
			}
			
			// free at last
			freeValuesArray(values_arr, cnt);
		}
		else
		 ret = 1;
	}
	return ret;
}

int process_video_size(const char *buf, char *max_size)
{
	// max default value and default values is 4096
	char default_value[4096] = {0}, default_values[4096] = {0};
	int ret;
	ret = getKeyDefaultAndValues(buf, "MtkCameraParameters::KEY_VIDEO_SIZE", "ITEM_AS_DEFAULT_", "ITEM_AS_VALUES_", default_value, default_values);
	if(ret >= 2)		// at least include default_value and default_values
	{
		char **values_arr;
		int cnt;
		int generateSizeCnt;
		char **genSizeValues;
		int w, h;
			
		//printf("default_value:%s, default_values:%s\n", default_value, default_values);
		cnt = split_str(default_values, ",", &values_arr);
		if(cnt > 0)
		{
			int align_data = 16;
			//dumpValuesArray(values_arr, cnt);
			
			trim_str_values(values_arr, cnt);
			fix_str_values_quoto(values_arr, cnt);
			trim_str_values(values_arr, cnt);
			//dumpValuesArray(values_arr, cnt);
			
			// validate align
			#if 0
			ret = validate_arrs(values_arr, cnt, VALIDATE_INFO_ALIGN_XX, &align_data);
			if(ret == 0)
				printf("validate align ok!\n");
			else
				printf("validate align Failed, failed items count:%d!\n", ret);
			#endif
				
			// validate none blank
			ret = validate_arrs(values_arr, cnt, VALIDATE_INFO_NONE_BLANK, NULL);
			if(ret == 0)
				printf("validate none blank ok!\n");
			else
				printf("validate none blank Failed, failed items count:%d!\n", ret);
			
			// validate must included video sizes
			ret = validate_arrs(values_arr, cnt, VALIDATE_INFO_VIDEO_SIZE_MUST_INCLUDED, max_size);
			if(ret == 0)
				printf("validate must included video sizes ok!\n");
			else
				printf("validate must included video sizes Failed, failed items count:%d!\n", ret);
			
			freeValuesArray(values_arr, cnt);
		}
		else
		 ret = 1;
	}
	return ret;
}