#include "common_local.h"

const char *s = "C6H5OH";

double molar_mass[] = {12.01, 1.008, 16.00, 14.01};

int grab_max_num_in_str(const char **s)
{
	int n = 0;
	const char *ps = *s;
	++ps;
	while(isdigit(*ps)) {
		n = n * 10 + (*ps - '0');
		++ps;
	}
	*s =  ps;
	if(n == 0)
		n = 1;
	return n;
}

int main()
{
	char *ps = (char *)s;
	double sum = 0;
	while(*ps) {
		if(*ps == 'C')
			sum += molar_mass[0] * grab_max_num_in_str(&ps);
		if(*ps == 'H')
			sum += molar_mass[1] * grab_max_num_in_str(&ps);
		if(*ps == 'O')
			sum += molar_mass[2] * grab_max_num_in_str(&ps);
		if(*ps == 'N')
			sum += molar_mass[3] * grab_max_num_in_str(&ps);
	}
    printf("Molar Mass Sum: %f\n", sum);
    return 0;
}
