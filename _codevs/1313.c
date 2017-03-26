#include <stdio.h> 
#include <math.h> 

int	is_prime(long n)
{
	long i = 2;

	while(i <= n / 2) {
		if(n % i == 0)
			return 0;
		++i;
	}
	return 1;
}

// a bad implemented
long get_bigger_prime_divisor_bad(long n)
{
	long i = n / 2;

	while(i >= 2) {
		// printf("[debug] i:%d\n", i);
		if(is_prime(i) && (n / i * i == n) && is_prime(n / i))
			return i;
		--i;
	}
	return -1;	// impossible
}

long arr[128];
long get_bigger_prime_divisor(long n)
{
	long i = 0;
	long k = 2;
	long v = (long)(sqrt(n) + 1);
	for(; k <= v; ++k) {
		if(n % k == 0) {
			arr[i++] = k;
			n /= k;
			if(n == 1)
				break;
		}
	}
	if(n > 1)
		arr[i++] = n;

	if(i >= 1)	
		return arr[i - 1];	
	return arr[0];
}

int main()
{
	long n;
	long bigger_prime;
	scanf("%ld", &n);
	
	bigger_prime = get_bigger_prime_divisor(n);
	printf("%ld\n", bigger_prime);
    return 0;
}
