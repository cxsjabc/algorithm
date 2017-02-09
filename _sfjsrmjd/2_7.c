#include <stdio.h>
#include <unistd.h>

void print_hex(double n)
{
	int i;
	printf("0x");
	for(i = 0; i < sizeof(n); ++i) {
		printf("%2X", *((unsigned char *)&n + i));
	}
	printf("\n");
}

int main()
{
	double i;
	double k = 2;
	
	print_hex(2);
	for(i = 0; i != 2; i += 0.1) {
		printf("%.8f\n", i);
		//usleep(100000);
		if(i > 2)
			break;
		print_hex(i);
	}

    return 0;
}
