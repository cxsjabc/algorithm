#include <stdio.h>

#define FILE_NAME unknown 

#define DATA_IN   "unknown.in"
#define DATA_OUT  "unknown.out"

int main()
{
	freopen(DATA_IN, "r", stdin);
	freopen(DATA_OUT, "w", stdout);

    return 0;
}
