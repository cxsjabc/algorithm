#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "time_xi.h"
#include "array.h"

#define PN(n)	printf(#n " is %d\n", (n));
#define PC(n)	printf(#n " is %c\n", (n));
#define PU(n)	printf(#n " is %u\n", (n));
#define PL(n)	printf(#n " is %ld\n", (n));
#define PP(n)	printf(#n " is %p\n", (n));

#define PD(n)	printf(#n " is %f\n", (n));

#define P_HERE()	printf("execute %s@%d\n", __FUNCTION__, __LINE__);

#define	LOG		printf

#ifndef _LOG_ENABLE
#define _LOG_ENABLE 1
#endif
// it needs macro: _LOG_ENABLE
#define	LOG_HERE	do { \
						if(_LOG_ENABLE && _LOG_LEVEL == LOG_LEVEL_VERBOSE) \
							printf("Log Here:%s@%d\n", __FUNCTION__, __LINE__); \
					} while(0)

enum 
{
	LOG_LEVEL_VERBOSE,
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFO,
	LOG_LEVEL_WARNING,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_FATAL,

	LOG_LEVEL_MAX
};

#ifndef _LOG_LEVEL
#define _LOG_LEVEL LOG_LEVEL_DEBUG
#endif
// log level: VERBOSE,DEBUG,INFO,WARNING,ERROR,FATAL
// it needs macro: _LOG_LEVEL
#define LOG_V(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL == LOG_LEVEL_VERBOSE) \
				printf("[V]" fmt "\n", ##args); \
		} while(0)	

#define LOG_D(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_DEBUG) \
				printf("[D]" fmt "\n", ##args); \
		} while(0)	

#define LOG_I(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_INFO) \
				printf("[I]" fmt "\n", ##args); \
		} while(0)	

#define LOG_W(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_WARNING) \
				printf("[W]" fmt "\n", ##args); \
		} while(0)	


#define LOG_E(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_ERROR) \
				printf("[E]" fmt "\n", ##args); \
		} while(0)	


#define LOG_F(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_FATAL) \
				printf("[F]" fmt "\n", ##args); \
		} while(0)	

#ifndef MAX
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b)  ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX3
#define MAX3(a, b, c)  (MAX(MAX((a), (b)), (c)))
#endif

#ifndef MIN3
#define MIN3(a, b, c)  (MIN(MIN((a), (b)), (c)))
#endif


#define ARR_SIZE(arr)		(sizeof(arr) / sizeof(arr[0]))

static inline void swap_by_addr(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

static inline void print_arr(int *arr, int size)
{
	int i = 0;

	while(i < size) {
		printf("%d ", arr[i]);
		++i;
	}
	printf("\n");
}

#if 0
static int max_in_arr(int arr[], int start, int end)
{
	int max = arr[start];
	int i = start + 1;
	int max_index = start;
	while(i <= end) {
		if(arr[i] > max) {
			max = arr[i];
			max_index = i;
		}
		++i;
	}
	return max_index;
}

#endif

void print_by_byte(const void *p, int size);

#endif
