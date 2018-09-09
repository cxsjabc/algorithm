#include "common_local.h"

int get_bytes(int len)
{
	return (len + 7) / 8;
}

int get_byte_bit(int len)
{
	return (len + 7) % 8;
}

int main()
{
    printf("%d\n", 0);
    return 0;
}
