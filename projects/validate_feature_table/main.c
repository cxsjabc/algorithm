#include <stdio.h>
#include <string.h>
#include "size.h"
#include "str_util.h"
#include "common.h"
#include "validate_info.h"
#include "process_internal.h"

//#define FILE_NAME "config.ftbl.gc2235_pic_size.h"
#define FILE_NAME "config.ftbl.gc2235mipi_raw.h"

void show_help_info(char *argv[])
{
	printf("Usage: \n\t %s (-max_pic_size 1280x720) (-max_prv_size 1920x1080) (-max_video_size 1920x1088)\n", argv[0]);
	printf("\t %s\n", argv[0]);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	int ret = 0;
	char buf[4096] = {0};
	char *buf1 = NULL;
	unsigned int size;	
	unsigned int read_ret;	
	char *search_start;
	int ret1;
	char *max_pic_size = NULL, *max_prv_size = NULL, *max_video_size = NULL;
	int show_help = 0;

	// parse the argv
	if(argc > 1)
	{
		int i = 1;
		while(i < argc)
		{
			if(strcmp(argv[i], "-max_pic_size") == 0 && i + 1 < argc)
			{
				max_pic_size = argv[i + 1];
				++i;
			}
			
			if(strcmp(argv[i], "-max_prv_size") == 0 && i + 1 < argc)
			{
				max_prv_size = argv[i + 1];
				++i;
			}
			
			if(strcmp(argv[i], "-max_video_size") == 0 && i + 1 < argc)
			{
				max_video_size = argv[i + 1];
				++i;
			}
			
			if(strcmp(argv[i], "-h") == 0)
			{
				show_help = 1;
				show_help_info(argv);
				return 0;
			}
			
			++i;
		}
	}

	// file size
	fp = fopen(FILE_NAME, "r");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	printf("file size:%u\n", size);

	// allocate buffer with file size
	buf1 = (char *)malloc(size + 1);
	if(!buf1)
	{
		printf("malloc buf failed!\n");
		ret = -1;
		goto label_fail;
	}
	
	// read file to buffer
	fseek(fp, 0, SEEK_SET);
	read_ret = fread(buf1, size , 1, fp);
	if(read_ret != 1)
	{
		printf("read file failed!\n");
		ret = -1;
		goto label_fail;
	}
	// print buffer
	//printf("buffer:[[%s]]\n", buf1);	

	// picture size/preview size/video size
	ret = process_picture_size(buf1, max_pic_size);
	ret = process_preview_size(buf1, max_prv_size);
	ret = process_video_size(buf1, max_video_size);

label_fail:
	if(fp)
		fclose(fp);
	if(buf1)
		free(buf1);
	return ret;
}
