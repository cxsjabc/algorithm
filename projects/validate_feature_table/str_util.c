#include "str_util.h"
#include "common_local.h"
#include "size.h"
#include <stdlib.h>
#include <stdio.h>

int isStrHasPrefix(const char *s, const char prefix)
{
	while(*s)
	{
		if(*s == prefix)
			return 1;
		if(*s != ' ' || *s != '\t' || *s != '\n')
			return 0;
		++s;
	}
	return 0;
}

int isStrHasPostfix(const char *s, const char postfix)
{
	unsigned int len = strlen(s);
	if(len == 0)
		return 0;
	while(--len)
	{
		char temp = *(s + len);
		if(temp == postfix)
			return 1;
		if(temp != ' ' || temp != '\t' || temp != '\n')
			return 0;
	}
	return 0;
}

isStrContainChar(const char *s, const char c)
{
	while(*s)
	{
		if(*s == c)
			return 1;
		++s;
	}
	return 0;
}

int parseStrToSize(const char *s, int *w, int *h)
{
	int ret;
	*w = *h = 0;
	
	ret = sscanf(s, "%dx%d", w, h);	
	if(ret == 2)
		goto label_exit;
		
	ret = sscanf(s, "\"%dx%d\"", w, h);	
	if(ret < 2)
	{
		printf("size:%s invalid!\n", s);
		return 0;
	}
	
label_exit:
	if(ret == 2)
	{
		return 1;
	}
	printf("parseStrToSize failed, s:[%s]\n", ret, s);
	return 0;	
}

int isSizeStrValid(const char *s)
{
	int ret;
	int w, h;
	ret = sscanf(s, "%dx%d", &w, &h);	
	if(ret < 0)
	{
		printf("size:%s invalid!\n", s);
		return 0;
	}
	ret = sscanf(s, "\"%dx%d\"", &w, &h);	
	if(ret < 0)
	{
		printf("size:%s invalid!\n", s);
		return 0;
	}
	if(ret == 2)
		return 1;

	return 0;
}

int isBlank(char c)
{
	return ((c == ' ') || (c == '\t') || (c == '\n'));
}

int isStrBlank(const char *s)
{
	int ret = 1;
	while(*s)
	{
		if(!isBlank(*s))
			return 0;
		++s;
	}
	
	return ret;
}

char *copy_string_by_start_end(char *dest, const char *src_start, const char *src_end)
{
	char *dest_begin = dest;
	while(src_start != src_end)
	{
		*dest = *src_start;
		++src_start;
		++dest;
	}
	return dest_begin;
}

int getKeyDefaultAndValues(const char *buf, const char *key, const char *default_value_key, const char *default_values_key, char *default_value, char *default_values)
{
	int ret = 0;
	char *search_start;
	
	if(search_start = strstr(buf, key))	// key is like: MtkCameraParameters::KEY_PICTURE_SIZE
	{
		char *item_default_begin, *item_default_value_begin, *item_default_value_end;
		char *item_defaults_begin, *item_default_values_begin, *item_default_values_end;
		int w, h;
		
		printf("contains key:%s\n", key);
		// search ITEM_AS_DEFAULT
		item_default_begin = strstr(search_start, default_value_key);		// default_value_key is like: ITEM_AS_DEFAULT_
		//printf("item default begin:%s\n", item_default_begin);
		if(item_default_begin == NULL)
		{
			printf("search ITEM_AS_DEFAULT_ fail!\n");
			goto label_fail;
		}
		//LOG_HERE;
		item_default_value_begin = strstr(item_default_begin, "(");
		//LOG_HERE;
		item_default_value_end = strstr(item_default_begin, ")");
		//LOG_HERE;
		if(item_default_value_begin == NULL || item_default_value_end == NULL)
		{
			printf("item default value begin/end failed!\n");
			goto label_fail;
		}
		//LOG_HERE;
		//printf("item begin:%p, end:%p\n", item_default_value_begin, item_default_value_end);
		copy_string_by_start_end(default_value, item_default_value_begin + 1, item_default_value_end);
		//printf("default value:[%s]\n", default_value);
		++ret;
		
		// preprocess
		preprocess_str(default_value);
		//printf("After preprocess: default value:[%s]\n", default_value);
		
		// parse the string 
		parseStrToSize(default_value, &w, &h);
		printf("w:%d, h:%d, is16Aligned:%s, sizeRatio:%s\n", w, h, TO_BOOL_STR(isSize16Aligned(w, h)), getSizeRatioStr(w, h));
		
		// search ITEM_AS_VALUES_
		item_defaults_begin = strstr(item_default_value_begin, default_values_key);		// default_values_key is like: ITEM_AS_VALUES_
		//printf("item default values begin:%s\n", item_defaults_begin);
		if(item_defaults_begin == NULL)
		{
			printf("search ITEM_AS_VALUES_ fail!\n");
			goto label_fail;
		}
		//LOG_HERE;
		item_default_values_begin = strstr(item_defaults_begin, "(");
		//LOG_HERE;
		item_default_values_end = strstr(item_defaults_begin, ")");
		//LOG_HERE;
		if(item_default_values_begin == NULL || item_default_values_end == NULL)
		{
			printf("item default values begin/end failed!\n");
			goto label_fail;
		}
		//LOG_HERE;
		//printf("item begin:%p, end:%p\n", item_default_value_begin, item_default_value_end);
		copy_string_by_start_end(default_values, item_default_values_begin + 1, item_default_values_end);
		++ret;
		//printf("default values:[%s]\n", default_values);
		
		// preprocess
		preprocess_str(default_values);
		//printf("After preprocess: default values:[%s]\n", default_values);
		
	}
	return ret;
	
label_fail:
	return ret;
}

// like c preprocess, remove the // comments and /* */ comments, filled with space ' '
int preprocess_str(char *s)
{
	int ret = 0;
	while(*s)
	{
		if(*s == '/')
		{
			if(*(s + 1) == '/')
			{
				char *temp = s + 2;
				// set zero for the line started from "//"
				*s = *(s + 1) = ' ';
				
				while(*temp != '\n' && *temp)
				{
					*temp = ' ';
					++temp;
				}
				++ret;
			}
			else if(*(s + 1) == '*')
			{
				// search the next token "*/"
				char *temp = s + 2;
				char *temp1 = strstr(s + 2, "*/");
				if(temp1)
				{
					*s = *(s + 1) = ' ';
					while(temp < temp1)
					{
						*temp = ' ';
						++temp;
					}
					*temp1 = *(temp1 + 1) = ' ';
					//s = temp1 + 2;
										
					++ret;					
					//continue;
				}
			}
		}
		
		++s;
	}
	
	return ret;
}

int	split_str(const char *s, const char *delimiter, char ***str_arr)
{
	char *p;
	int i = 0;
	int cnt = 0;
	*str_arr = (char **)malloc(128 * sizeof(char *));
	if(!(*str_arr))
		return 0;
		
	p = strtok(s, delimiter);
	while(p)
	{
		char *temp;
		
		if(isStrBlank(p))
			goto goon_strtok;
			
		temp = (char *)malloc(strlen(p) + 1);
		if(!temp)
			goto label_fail;
			
		strcpy(temp, p);
		(*str_arr)[i] = temp;
		//printf("One Token:[%s] \n", p);
		++cnt;
		++i;
		
goon_strtok:		
		p = strtok(NULL, delimiter);
	}
	return cnt;
	
label_fail:	
	return 0;
}

int str_trim(char *s)
{
	unsigned int len = strlen(s);
	char *s_end = s + len - 1;
	char *s_begin = s;
	
	while(isBlank(*s))
		++s;
	while(isBlank(*s_end))
		--s_end;
		
	// do nothing
	if(s == s_end)
		return 0;
		
	memmove(s_begin, s, s_end - s + 1);
	*(s_begin + (s_end - s + 1)) = '\0';
	
	return 1;
}

int trim_str_values(char **str_values, int cnt)
{
	int i = 0;
	int temp = 0;
	for(; i < cnt; ++i)
	{
		int trim_ret = str_trim(str_values[i]);
		temp += trim_ret;
	}
	return temp;
}

void dumpValuesArray(char **values_arr, int cnt)
{
	int i = 0;
	if(cnt < 1)
		return;
	printf("[%s]", values_arr[i]);
	for(i = 1; i < cnt; ++i)
	{
		printf("[%s]", values_arr[i]);
		if((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");
}


void freeValuesArray(char **values_arr, int cnt)
{
	int i;
	for(i = 0; i < cnt; ++i)
		if(values_arr[i])
			free(values_arr[i]);
			
	free(values_arr);
}

int isStrInArr(const char *s, const char **arr, int cnt)
{
	int ret = 0;
	int i;
	
	for(i = 0; i < cnt; ++i)
	{
		if(strcmp(s, arr[i]) == 0)
			return 1;
	}
	
	return ret;
}

void fix_str_values_quoto(char **values_arr, int cnt)
{
	int i = 0;
	
	for(; i < cnt; ++i)
	{
		char *s = values_arr[i];
		//printf("%s\n", s);
		if(s[0] == '\"')
			s[0] = ' ';
		if(s[strlen(s) - 1] == '\"')
			s[strlen(s) - 1] = ' ';
		//printf("%s\n", s);
	}
	
}
