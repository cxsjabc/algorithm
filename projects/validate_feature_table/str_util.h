#ifndef STR_UTIL_H
#define STR_UTIL_H

typedef enum 
{
	SIZE_STATUS_OK = 0,
	SIZE_STATUS_HAS_BLANKS = 1,
	SIZE_STATUS_NOT_INTEGER = 2,
	SIZE_STATUS_NOT_INCLUDE_X = 4,
	SIZE_STATUS_NOT_16_ALIGNED = 8,

	SIZE_STATUS_MAX = 1 << 30,
}SIZE_STATUS;

int isBlank(char c);
int isStrBlank(const char *s);

int parseStrToSize(const char *s, int *w, int *h);
int isSizeStrValid(const char *s);

char *copy_string_by_start_end(char *dest, const char *src_start, const char *src_end);

int getKeyDefaultAndValues(const char *buf, const char *key, const char *default_value_key, const char *default_values_key, char *default_value, char *default_values);

int	split_str(const char *s, const char *delimiter, char ***str_arr);

int str_trim(char *s);

void dumpValuesArray(char **values_arr, int cnt);

void freeValuesArray(char **values_arr, int cnt);

int preprocess_str(char *s);

int isStrInArr(const char *s, const char **arr, int cnt);

void fix_str_values_quoto(char **values_arr, int cnt);

#endif
