#ifndef SIZE_H
#define SIZE_H


typedef enum 
{
	SIZE_RATIO_START,
	SIZE_RATIO_4_3,
	SIZE_RATIO_3_2,
	SIZE_RATIO_5_3,
	SIZE_RATIO_16_9,

	SIZE_RATIO_UNKNOWN,
	SIZE_RATIO_MAX,
}SIZE_RATIO;

typedef struct 
{
	SIZE_RATIO sr;
	const char *tip;
}SizeRatio;

// the array should sync with SIZE_RATIO
extern const SizeRatio gSizeRatioArr[];

extern const char *gVideoFixedSizes[9];

int isSize16Aligned(int w, int h);
int isSizeAligned(int width, int height, int align);

int isSize4_3(int w, int h);
int isSize3_2(int w, int h);
int isSize5_3(int w, int h);
int isSize16_9(int w, int h);

int getSizeRatio(int w, int h);
char *getSizeRatioStr(int w, int h);


int	generateSizeValues(int max_w, int max_h, char ***size_arr, int force_ratio);

int getBiggestSize(char **arr, int cnt, int *w, int *h);

#endif
