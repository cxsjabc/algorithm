#ifndef TIME_XI_H
#define TIME_XI_H

#include <stdio.h>

#define TIME_START(times)	\
	{  \
		clock_t __19870814_xixi_tag_you_not_used_start, __19870814_xixi_tag_you_not_used_finish; \
		int __19870814_xixi_tag_you_not_used_i; \
		__19870814_xixi_tag_you_not_used_start = clock(); \
				\
		for(__19870814_xixi_tag_you_not_used_i = 0; __19870814_xixi_tag_you_not_used_i < (times); ++__19870814_xixi_tag_you_not_used_i) \
		{ 

#define TIME_END \
		} \
		__19870814_xixi_tag_you_not_used_finish = clock(); \
		printf("Time Elapsed:%5f seconds\n", 1.0 * (__19870814_xixi_tag_you_not_used_finish - __19870814_xixi_tag_you_not_used_start) / CLOCKS_PER_SEC); \
	} 

#endif
