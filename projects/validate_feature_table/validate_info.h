#ifndef VALIDATE_INFO_H
#define VALIDATE_INFO_H

typedef enum
{
	VALIDATE_INFO_ALIGN_XX,
	VALIDATE_INFO_MIN_WIDTH,
	VALIDATE_INFO_MIN_HEIGHT,
	VALIDATE_INFO_MAX_WIDTH,
	VALIDATE_INFO_MAX_HEIGHT,
	VALIDATE_INFO_UNIQUE,
	VALIDATE_INFO_NONE_BLANK,
	VALIDATE_INFO_VIDEO_SIZE_MUST_INCLUDED,

	VALIDATE_INFO_MAX,

}VALIDATE_INFO;

int validate(const char *s, VALIDATE_INFO validate_info, const void *data);
int validate_arrs(const char **arr, int cnt, VALIDATE_INFO validate_info, const void *data);

#endif
