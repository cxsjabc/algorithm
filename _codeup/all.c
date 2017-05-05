#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b;

	while(scanf("%d%d", &a, &b) == 2) {
		printf("%d\n", a + b);
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;
	int a, b;

	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b;

	while(scanf("%d%d", &a, &b) == 2) {
		if(a == 0 && b == 0)
			break;
		printf("%d\n", a + b);
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int c;
	int n;

	while(scanf("%d", &c) == 1 && c > 0) {
		int sum = 0;
		while(c--) {
			scanf("%d", &n);
			sum += n;
		}
		printf("%d\n", sum);
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t, c;
	int n;
	
	scanf("%d", &t);
	while(t--) {
		while(scanf("%d", &c) == 1 && c > 0) {
			int sum = 0;
			while(c--) {
				scanf("%d", &n);
				sum += n;
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int c;
	int n;

	while(scanf("%d", &c) == 1 && c > 0) {
		int sum = 0;
		while(c--) {
			scanf("%d", &n);
			sum += n;
		}
		printf("%d\n", sum);
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b;

	while(scanf("%d%d", &a, &b) == 2) {
		printf("%d\n\n", a + b);
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t, c;
	int n;
	
	scanf("%d", &t);
	while(t--) {
		while(scanf("%d", &c) == 1 && c > 0) {
			int sum = 0;
			while(c--) {
				scanf("%d", &n);
				sum += n;
			}
			printf("%d\n", sum);
			if(t != 0)
				printf("\n");
		}
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int i;
	int v;

	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &v);
		printf("%c", (char)v);
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 0;
	double sum = 0;
	double s;

	while(i < 12) {
		scanf("%lf", &s);
		sum += s;
		++i;
	}
	printf("￥%.2f\n", sum / 12);
	return 0;
}
#include <stdio.h> 
// i don't know why this can't pass?

#include <stdlib.h> 
#include <math.h> 


char s[] = {'A', 'B', 'C', 'D', 'F'};
int	 score[] = {4, 3, 2, 1, 0};

int	is_in_s(char c)
{
	return c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'F';
}

int	get_score(char c)
{
	int ret;
	switch(c) {
		case 'A':
			ret = 4;
		break;
		case 'B':
			ret = 3;
		break;
		case 'C':
			ret = 2;
		break;
		case 'D':
			ret = 1;
		break;
		case 'F':
			ret = 0;
		break;
		default:
			ret = -1;
		break;
	}
	return ret;
}

int main()
{
	double sum = 0;
	int ch;
	int ch_in_abcde = 1;
	int cnt = 0;
	int first = 1;

	while(1) {
		ch = getchar();
		if(ch == EOF)
			break;
		if(ch == '\n') {
			if(!first)
				printf("\n");
			else
				first = 0;

			if(ch_in_abcde)
				printf("%.2f", sum / cnt);
			else
				printf("Unknown");
			cnt = 0;
			ch_in_abcde = 1;
			sum = 0;
		}
		else if(is_in_s(ch))
			sum += get_score(ch), ++cnt;
		else if(ch == ' ')
			continue;
		else
			ch_in_abcde = 0;
	}	

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char s[128];	// just assume max char arr size is: 128
	int first = 1;

	while(gets(s)) {
		int i = 0;
		double sum = 0;
		int cnt = 0;
		char *p = s;
		int err = 0;
		
		if(!first)
			printf("\n");
		else
			first = 0;

		while(*p) {
			if(*p == 'A')
				sum += 4, ++cnt;
			else if(*p == 'B')
				sum += 3, ++cnt;
			else if(*p == 'C')
				sum += 2, ++cnt;
			else if(*p == 'D')
				sum += 1, ++cnt;
			else if(*p == 'F')
				sum += 0, ++cnt;
			else if(*p == ' ') {
				++p;
				continue;
			}
			else {
				err = 1;
				break;
			}
			++p;
		}
		if(!err)
			printf("%.2f", sum / cnt);
		else
			printf("Unknown");
	}

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;

	scanf("%d", &t);
	while(t--) {
		int v1[3], v2[3];
		int i;
		int new = 0;
		char *p;

		for(i = 0; i < 3; ++i)
			scanf("%d", &v1[i]);		
		for(i = 0; i < 3; ++i)
			scanf("%d", &v2[i]);		

		for(i = 0; i < 3; ++i) {
			if(v1[i] > v2[i]) {
				new = 1;
				break;
			}
			else if(v1[i] < v2[i]) {
				new = -1;
				break;
			}
		}

		if(new == 1)
			p = "First";
		else if(new == -1)
			p = "Second";
		else
			p = "Same";	

		printf("%s", p);
		if(t != 0)
			printf("\n");	
	}

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double m;
	int n = 12;
	double exp_rate;
	double max_exp_rate = 0;

	scanf("%lf", &m);
	while(n--) {
		scanf("%lf", &exp_rate);
		if(exp_rate > max_exp_rate)
			max_exp_rate = exp_rate;
	}
	printf("%.2f\n", m * max_exp_rate);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n, v;
	int i;
	int sum, avg;
	int arr[51];
	int move;

	while(1) {
		scanf("%d", &n);
		if(n == 0)
			break;
		sum = 0;
		move = 0;
		for(i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		avg = sum / n;

		for(i = 0; i < n; ++i) {
			if(arr[i] > avg)
				move += (arr[i] - avg);	
		}
		printf("%d\n", move);
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;
	int n;

	scanf("%d", &t);
	while(t--) {
		int i, j;

		scanf("%d", &n);
		for(i = 0; i < n; ++i) {
			for(j = 0; j < n; ++j) {
				printf("%d", (i + 1) * (j + 1));
				if(j != n - 1)
					printf(" ");
			}
			putchar('\n');
		}
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;

	scanf("%d", &t);
	while(t--) {
		int n, k;
		int s[1000];
		int i;
		int c = 0;
	
		scanf("%d%d", &n, &k);
		for(i = 0; i < n; ++i)
			scanf("%d", &s[i]);		
		
		for(i = 0; i < n; ++i) {
			if(i != k - 1 && s[i] > s[k - 1])
				++c;		
		}

		printf("%d\n", c);
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


/* Not Right */
int main()
{
	int t;
	double d;
	int n;
	long long l;

	scanf("%d", &t);
	while(t--) {
		int i = 0;
		scanf("%lf%d", &d, &n);
		while(i++ < n) {
			d *= 10;
		}
		l = (long long)d;
		printf("%ld\n", l % 10);
	}

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int main()
{
	int t;
	char s[128];
	int n;

	scanf("%d", &t);
	while(t--) {
		int i = 0;
		memset(s, 0, 128);
		scanf("%s%d", s, &n);
		while(s[i]) {
			if(s[i] == '.')
				break;
			++i;
		}
		printf("%c\n", s[i + n]);
	}

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
// Not right!
int main()
{
	int t;
	char s[1024];	

	scanf("%d", &t);
	getchar();

	while(t--) {
		int i = 0, j = 0;
		int k;
	
		gets(s);
		while(1) {
			while(s[j] && s[j] != ' ') {
				++j;
			}
			for(k = j - 1; k >= i; --k)
				printf("%c", s[k]);
			while(s[j] && s[j] == ' ') {
				printf(" ");
				++j;
			}
			if(s[j] == '\0')
				break;
			i = j;
		}
		printf("\n");
	}

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;

	scanf("%d", &t);
	while(t--) {
		int n;
		int a[10];
		int i;
		int min, smin;

		scanf("%d", &n);

		scanf("%d", &a[0]);
		min = smin = a[0];
		for(i = 1; i < n; ++i) {
			scanf("%d", &a[i]);
			if(a[i] < min)
				smin = min, min = a[i];
			else if(a[i] > min && a[i] < smin)
				smin = a[i];
			else if(a[i] > smin && smin == min)
				smin = a[i];
		}
		
		if(min != smin)	
			printf("%d\n", smin);
		else
			printf("NO\n");
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;

	scanf("%d", &t);
	while(t--) {
		int n;
		int first = 1, f = 0;

		scanf("%d", &n);

		while(n != 1) {
			if(n % 2 == 1) {
				if(!first)
					printf(" ");
				else
					first = 0;
				f = 1;
				printf("%d", n);
			}

			if(n % 2 == 0)
				n /= 2;
			else
				n = 3 * n + 1;
		}

		if(f == 0)
			printf("No number can be output !\n");
		else
			printf("\n");
	}


	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	printf("This is a C program.\n");
	return 0;
}

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a = 123, b = 456;

	printf("sum is %d\n", a + b);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b;
	int max;

	scanf("%d,%d", &a, &b);
	max = (a > b) ? a : b;
	printf("max=%d\n", max);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	printf("******************************\n");
	printf("Very good!\n");
	printf("******************************\n");
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b, c;
	int max;

	scanf("%d,%d,%d", &a, &b, &c);

	if(a > b)
		max = a;
	else
		max = b;
	if(c > max)
		max = c;

	printf("max=%d\n", max);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	printf("%d\n", 1 * 2 * 3 * 4 * 5);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char n[1024];
	int s;
	int t = 50;

	while(t--) {
		scanf("%s%d", n, &s);
		if(s >= 80)
			printf("%s %d\n", n, s);
	}
	
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	is_leap_year(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main()
{
	int y;

	scanf("%d", &y);
	printf("%s\n", is_leap_year(y) ? "leap year" : "not leap year");
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double sum = 0;
	int n = 100;
	int flag = 1;
	int i = 1;

	while(i <= n) {
		sum += (1. / i * flag);	
	
		flag = -flag;
		++i;
	}

	printf("%.8f\n", sum);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_prime(int n)
{
	int i;
	
	if(n < 2)
		return 0;

	for(i = 2; i <= n / 2; ++i)
		if(n % i == 0)
			return 0;
	return 1;
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%s\n", is_prime(n) ? "prime" : "not prime");
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int t = 9;
	int max;

	scanf("%d", &max);
	while(t--) {
		scanf("%d", &n);
		if(n > max)
			max = n;
	}

	printf("%d\n", max);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b, c;
	int m1, m2, m3;

	scanf("%d%d%d", &a, &b, &c);
	
	if(a > b)
		m1 = b, m2 = a;
	else
		m1 = a, m2 = b;

	if(c >= m2)
		m3 = c;
	else if(c <= m1)
		m3 = m2, m2 = m1, m1 = c;
	else
		m3 = m2, m2 = c;

	printf("%d %d %d\n", m1, m2, m3);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n = 100;
	int i = 1;
	int sum = 0;

	while(i <= 100)
		sum += i, ++i;

	printf("%d\n", sum);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_exact_div_by_3_5(int n)
{
	return (n % 3 == 0 && n % 5 == 0);
}

int main()
{
	int n;
	
	scanf("%d", &n);
	printf("%s\n", is_exact_div_by_3_5(n) ? "can" : "cannot");
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_prime(int n)
{
	int i;
	
	if(n < 2)
		return 0;

	for(i = 2; i <= n / 2; ++i)
		if(n % i == 0)
			return 0;
	return 1;
}

int main()
{
	int i;

	for(i = 100; i <= 200; ++i) {
		if(is_prime(i))
			printf("%d\n", i);
	}

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int gcd(int m, int n)
{
	int mod;

	if(n == 0)
		return m;

	mod = m % n;
	m = n;
	n = mod;

	return gcd(m, n);
}

int main()
{
	int m, n;

	scanf("%d%d", &m, &n);
	printf("%d\n", gcd(m, n));

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

// ax^2 + bx + c = 0
// return value: the root count, if return 1, the value is stored in v1.
int	get_equation_value(double a, double b, double c, double *v1, double *v2)
{
	double delta;
	int cnt;

	delta = b * b - 4 * a * c;
	if(delta < 0)
		cnt = 0;
	else if(fabs(delta) <= 1e-15)
		cnt = 1;
	else
		cnt = 2;

	if(cnt == 1)
		*v1 = -1 * b / (2 * a);
	else if(cnt == 2) {
		*v1 = (-1 * b - sqrt(delta)) / (2 * a);
		*v2 = (-1 * b + sqrt(delta)) / (2 * a);
	}
	return cnt;	
}

int main()
{
	int a, b, c;
	int ret;
	double v1, v2;

	scanf("%d%d%d", &a, &b, &c);

	ret = get_equation_value(a, b, c, &v1, &v2);
	if(ret == 0)
		printf("no answer\n");
	else if(ret == 1)
		printf("%.4f\n", v1);
	else if(ret == 2)
		printf("%.4f %.4f\n", v1, v2);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	is_leap_year(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main()
{
	int i;

	for(i = 1900; i <= 2000; ++i) {
		if(is_leap_year(i))
			printf("%d\n", i);
	}

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int	get_oct(int n, char *s)
{
	int i = 0;
	int flag = 1;
	int len;
	char *sb = s;

	if(n < 0)
		flag = -1, n = -n;

	if(n == 0) {	
		*s = '0';
		++s;
		*s = '\0';
		return 1;
	}

	if(flag == -1)
		*s++ = '-';

	while(n) {
		int temp;
		temp = n % 8;
		*s = temp + '0';

		n /= 8;
		++s;
	}
	*s = '\0';

	len = strlen(sb);
	if(flag == -1)
		--len, i = 0, sb++;
	for(; i < len / 2; ++i) {
		char temp = sb[i];
		sb[i] = sb[len - i - 1];
		sb[len - i - 1] = temp;
	}

	return 1;	
}

int	get_hex(int n, char *s)
{
	int i = 0;
	int flag = 1;
	int len;
	char *sb = s;

	if(n < 0)
		flag = -1, n = -n;

	if(n == 0) {	
		*s = '0';
		++s;
		*s = '\0';
		return 1;
	}

	if(flag == -1)
		*s++ = '-';

	while(n) {
		int temp;
		temp = n % 16;
		if(temp >= 0 && temp <= 9)
			*s = temp + '0';
		else
			*s = temp - 10 + 'a';
		n /= 16;
		++s;
	}
	*s = '\0';

	len = strlen(sb);
	if(flag == -1)
		--len, i = 0, ++sb;
	for(i = 0; i < len / 2; ++i) {
		char temp = sb[i];
		sb[i] = sb[len - i - 1];
		sb[len - i - 1] = temp;
	}
	return 1;	
}

int main()
{
	int t = 8;

	while(t--) {
		int n;
		char s[128], s1[128];

		scanf("%d", &n);
		get_oct(n, s);		
		get_hex(n, s1);		
		printf("%s %s\n", s, s1);
	}

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char a, b, c, d, e;

	a = 'C', b = 'h', c = 'i', d = 'n', e = 'a';
	printf("%c%c%c%c%c\n", a + 4, b + 4, c + 4, d + 4, e + 4);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double x, y;
	int a;

	scanf("%lf%d%lf", &x, &a, &y);
	printf("%.6f\n", x + (a % 3) * (int)(x + y) % 2 / 4);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double x, y;
	int a, b;

	scanf("%d%d%lf%lf", &a, &b, &x, &y);
	printf("%.6f\n", (float)(a + b) / 2 + (int)x % (int)y); 

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a;

	scanf("%d", &a);
	printf("%d\n", a += a);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a;

	scanf("%d", &a);
	printf("%d\n", a -= 2);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a;

	scanf("%d", &a);
	printf("%d\n", a *= 2 + 3);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a;

	scanf("%d", &a);
	printf("%d\n", a /= a + a);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, n;

	scanf("%d%d", &a, &n);
	printf("%d\n", a %= (n %= 2));

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a;

	scanf("%d", &a);
	printf("%d\n", a += a -= a *= a); 

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	putchar('B');
	putchar('O');
	putchar('Y');
	putchar('\n');
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int c;

	c = getchar();
	putchar(c);
	putchar('\n');

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	unsigned int a = 4294967295;
	int b = -2;

	printf("%d,%o,%x,%u\n", a, a, a, a);
	printf("%d,%o,%x,%u\n", b, b, b, b);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char c = 'a';
	int i = 97;

	printf("%c,%d\n", c, c);
	printf("%c,%d\n", i, i);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char *s = "CHINA";
	printf("%3s,%7.2s,%.4s,%-5.3s\n", s, s, s, s);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	float f1 = 111111.111, f2 = 222222.222;

	printf("%f\n", f1 + f2);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double f1 = 1111111111111.111111111, f2 = 2222222222222.222222222;

	printf("%.4f\n", f1 + f2);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	float f = 123.456;
	printf("%f,%10f,%10.2f,%.2f,%-10.2f\n", f, f, f, f, f);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double a, b, c;
	double p;

	scanf("%lf%lf%lf", &a, &b, &c);
	p = (a + b + c) / 2;

	printf("%.2f\n", sqrt(p * (p - a) * (p - b) * (p - c)));
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int ch;

	ch = getchar();
	printf("%c\n", ch + 32);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

// ax^2 + bx + c = 0
// return value: the root count, if return 1, the value is stored in v1.
int	get_equation_value(double a, double b, double c, double *v1, double *v2)
{
	double delta;
	int cnt;

	delta = b * b - 4 * a * c;
	if(delta < 0)
		cnt = 0;
	else if(fabs(delta) <= 1e-15)
		cnt = 1;
	else
		cnt = 2;

	if(cnt == 1)
		*v1 = -1 * b / (2 * a);
	else if(cnt == 2) {
		*v1 = (-1 * b - sqrt(delta)) / (2 * a);
		*v2 = (-1 * b + sqrt(delta)) / (2 * a);
	}
	return cnt;	
}

int main()
{
	int a, b, c;
	int ret;
	double v1, v2;

	scanf("%d%d%d", &a, &b, &c);

	ret = get_equation_value(a, b, c, &v1, &v2);
	if(ret == 0)
		printf("no answer\n");
	else if(ret == 1)
		printf("%.4f\n", v1);
	else if(ret == 2)
		printf("%.4f %.4f\n", v1, v2);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define PI	3.1415926

int main()
{
	double r, h;

	scanf("%lf%lf", &r, &h);

	printf("%.2f %.2f %.2f %.2f %.2f\n", 2 * PI * r, PI * r * r, PI * r * r * h,
			4 * PI * r * r, (4. / 3) * PI * r * r * r);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double f;

	scanf("%lf", &f);
	printf("%.2f\n", 5. / 9 * (f - 32));

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double a, b;

	scanf("%lf%lf", &a, &b);
	if(a > b)
		printf("%.2f %.2f\n", b, a);
	else
		printf("%.2f %.2f\n", a, b);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double a, b, c;
	double t;

	scanf("%lf%lf%lf", &a, &b, &c);
	if(a > b)
		t = a, a = b, b = t;
	if(c < a)
		t = c, c = b, b = a, a = t;
	if(c < b)
		t = c, c = b, b = t;

	printf("%.2f %.2f %.2f\n", a, b, c);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int f(int x)
{
	if(x < 0)
		return -1;
	else if(x == 0)
		return 0;
	else
		return 1;
}

int main()
{
	int x;

	scanf("%d", &x);
	printf("%d\n", f(x));

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int process_ch(int ch)
{
	if(ch >= 'A' && ch <= 'Z')
		return ch + 32;
	else
		return ch;	
}

int main()
{
	int ch;

	ch = getchar();

	printf("%c\n", process_ch(ch));

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	is_leap_year(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main()
{
	int y;

	scanf("%d", &y);
	printf("%s\n", is_leap_year(y) ? "leap year" : "not leap year");
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

// ax^2 + bx + c = 0
// return value: the root count, if return 1, the value is stored in v1.
int	get_equation_value(double a, double b, double c, 
						double *v1, double *v2, int *is_imaginary_root)
{
	double delta;
	int cnt;

	if(is_imaginary_root)
		*is_imaginary_root = 0;

	delta = b * b - 4 * a * c;
	if(delta < 0) {
		cnt = 2;
		if(is_imaginary_root)
			*is_imaginary_root = 1;
	}
	else if(fabs(delta) <= 1e-15)
		cnt = 1;
	else
		cnt = 2;

	if(cnt == 1)
		*v1 = -1 * b / (2 * a);
	else if(cnt == 2) {
		if(*is_imaginary_root == 1) {
			delta = -delta;
			*v1 = (-1. * b) / (2 * a);
			*v2 = sqrt(delta) / (2 * a);
			if(*v2 < 0)
				*v2 = -(*v2);
		} else {
			*v1 = (-b - sqrt(delta)) / (2 * a);
			*v2 = (-b + sqrt(delta)) / (2 * a);
		}
	}
	return cnt;	
}

int main()
{
	int a, b, c;
	int ret;
	double v1, v2;
	int is_imaginary_root;

	scanf("%d%d%d", &a, &b, &c);

	if(a == 0) {
		printf("not a quadratic\n");
		return 0;
	}
	
	ret = get_equation_value(a, b, c, &v1, &v2, &is_imaginary_root);
	if(ret == 0)
		printf("no answer\n");
	else if(ret == 1)
		printf("two equal roots:%.4f\n", v1);
	else if(ret == 2) {
		if(is_imaginary_root)
			printf("complex roots:%.4f+%.4fi %.4f-%.4fi\n", v1, v2, v1, v2);
		else
			printf("distinct real roots:%.4f %.4f\n", v1, v2);
	}
	
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double p, w;
	int s;
	double c;

	scanf("%lf%lf%d", &p, &w, &s);
	if(s < 250)
		c = p * w * s;
	else if(s < 500)
		c = p * w * s * (1 - 0.02);
	else if(s < 1000)
		c = p * w * s * (1 - 0.05);
	else if(s < 2000)
		c = p * w * s * (1 - 0.08);
	else if(s < 3000)
		c = p * w * s * (1 - 0.1);
	else
		c = p * w * s * (1 - 0.15);

	printf("%.4f\n", c);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b, c;
	int max;

	scanf("%d%d%d", &a, &b, &c);
	max = a;
	if(b > max)
		max = b;
	if(c > max)
		max = c;
	printf("%d\n", max);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int f(int x)
{
	if(x < 1)
		return x;
	else if(x < 10)
		return 2 * x - 1;
	else 
		return 3 * x - 11;
}

int main()
{
	int x;

	scanf("%d", &x);
	printf("%d\n", f(x));
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

char get_grade(int s)
{
	char g;	
	
	if(s >= 90)
		g = 'A';
	else if(s >= 80)
		g = 'B';
	else if(s >= 70)
		g = 'C';
	else if(s >= 60)
		g = 'D';
	else
		g = 'E';
	return g;
}

int main()
{
	int s;

	scanf("%d", &s);
	printf("%c\n", get_grade(s));
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int get_digits_cnt(int n)
{
	int c = 0;
	
	if(n == 0)
		return 1;

	while(n) {
		n /= 10;
		++c;
	}
	return c;
}

void print_each_digit(int n)
{
	int t = 0;
	int a[8];
	int i;

	if(n == 0) {
		printf("0 ");
		return;
	}
	
	while(n) {
		a[t++] = n % 10;
		n /= 10;	
	}

	for(i = 0; i < t / 2; ++i) {
		int temp = a[i];
		a[i] = a[t - i - 1];
		a[t - i - 1] = temp;
	}	

	for(i = 0; i < t; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

void print_each_digit_reverse(int n)
{
	int t = 0;
	int a[8];
	int i;

	if(n == 0) {
		printf("0 ");
		return;
	}
	
	while(n) {
		a[t++] = n % 10;
		n /= 10;	
	}

	for(i = 0; i < t; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", get_digits_cnt(n));
	print_each_digit(n);
	print_each_digit_reverse(n);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i;
	double t = 0;

	scanf("%d", &i);
	if(i <= 10e4)
		t = i * 0.1;
	else if(i <= 20e4)
		t = 10000 + (i - 10e4) * 0.075;
	else if(i <= 40e4)
		t = 10000 + 7500 + (i - 20e4) * 0.05;
	else if(i <= 60e4)
		t = 10000 + 7500 + 10000 + (i - 40e4) * 0.03;
	else if(i <= 100e4)
		t = 10000 + 7500 + 10000 + 6000 + (i - 60e4) * 0.015;
	else 
		t = 10000 + 7500 + 10000 + 6000 + 6000 + (i - 100e4) * 0.01;
	

	printf("%.2f\n", t);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void bubble_sort(int a[], int size)
{
	int i, j;

	for(i = 0; i < size - 1; ++i) {
		for(j = size - 1; j > i; --j) {
			if(a[j] < a[j - 1]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

int main()
{
	int a[4];
	int i = 0;
	int first = 1;

	while(i < 4) {
		scanf("%d", &a[i++]);
	}

	bubble_sort(a, 4);
	for(i = 0; i < 4; ++i) {
		if(first)
			first = !first;
		else
			printf(" ");
		printf("%d", a[i]);	
	}

	printf("\n");

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_in_tower(double x, double y)
{
	int xa[4] = {2, -2, 2, -2};
	int ya[4] = {2, 2, -2, -2};
	int i;
	int dis;
	int out_cnt = 0;

	for(i = 0; i < 4; ++i) {
		dis = (x - xa[i]) * (x - xa[i]) + (y - ya[i]) * (y - ya[i]);
		if(dis > 1) // if dis = sqrt(dis): then maybe fail
			++out_cnt;
	}
	
	if(out_cnt == 4)
		return 0;
	else
		return 1;
}

int main()
{
	double x, y;
	int t;

	scanf("%lf%lf", &x, &y);		
	t = is_in_tower(x, y);
	if(t)
		printf("%.2f\n", 10.);
	else
		printf("%.2f\n", 0.);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 1, n = 100;
	int sum = 0;

loop:
	if(i <= n) {
		sum += i;
		++i;
		goto loop;
	}

	printf("%d\n", sum);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 1;
	int sum = 0;

	while(i <= 100) {
		sum += i;
		++i;
	}
	printf("%d\n", sum);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 0;
	int sum = 0;

	do {
		sum += i;
		++i;
	} while(i <= 100);
	printf("%d\n", sum);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int j = 100, k = 200;
	int i;

	for(i = j; i <= k; ++i)
		if(i % 3 != 0)
			printf("%d ", i);

	printf("\n");
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int j = 100, k = 200;
	int i;

	for(i = j; i <= k - 1; i += 3) {
		printf("%d %d ", i, i + 1);
	}

	printf("\n");
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 1, j = 1;
	double pi_4 = 0;
	int flag = 1;	

	while(1) {
		double t = 1.0 * i / j * flag;

		if(fabs(t) < 1e-6)
			break;

		pi_4 += t;
		flag = -flag;
		j += 2;
	}

	pi_4 *= 4;
	printf("%.6f\n", pi_4);

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int f1 = 1, f2 = 1;	
	int i = 3, n = 40;

	printf("%d %d ", f1, f2);
	while(i <= 40) {
		int t = f1 + f2;
		printf("%d ", t);

		f1 = f2;
		f2 = t;
		++i;
	}
	printf("\n");
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_prime(int n)
{
	int i;
	
	if(n < 2)
		return 0;

	for(i = 2; i <= n / 2; ++i)
		if(n % i == 0)
			return 0;
	return 1;
}

int main()
{
	int i;

	scanf("%d", &i);
	if(is_prime(i))
		printf("prime\n");
	else
		printf("not prime\n");

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_prime(int n)
{
	int i;
	
	if(n < 2)
		return 0;

	for(i = 2; i <= n / 2; ++i)
		if(n % i == 0)
			return 0;
	return 1;
}

int main()
{
	int i;

	for(i = 100; i <= 200; ++i) {
		if(is_prime(i))
			printf("%d ", i);
	}
	printf("\n");

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void encrypt(char *s)
{
	while(*s) {
		if(*s >= 'A' && *s <= 'Z') {
			*s += 4;
			if(*s > 'Z')
				*s = (*s - 'Z' + 3) + 'A';

		}
		if(*s >= 'a' && *s <= 'z') {
			*s += 4;
			if(*s > 'z')
				*s = (*s - 'z' + 3) + 'a';
		}

		++s;
	}
}

int main()
{
	char s[128];

	gets(s);
	encrypt(s);
	printf("%s\n", s);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int gcd(int m, int n)
{
	int mod;

	if(n == 0)
		return m;

	mod = m % n;
	m = n;
	n = mod;

	return gcd(m, n);
}

int lmd(int m, int n)
{
	int g = gcd(m, n);
	return m * n / g;
}

int main()
{
	int m, n;

	scanf("%d%d", &m, &n);
	printf("%d %d\n", gcd(m, n), lmd(m, n));

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char str[128];
	int cc = 0, bc = 0, nc = 0, oc = 0;
	char * s;

	gets(str);
	s = str;

	while(*s) {
		if(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z')
			++cc;
		else if(*s == ' ')
			++bc;
		else if(*s >= '0' && *s <= '9')
			++nc;
		else
			++oc;

		++s;
	}
	printf("%d %d %d %d\n", cc, bc, nc, oc);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, n;
	long long s = 0;
	int i = 1;
	int v;

	scanf("%d%d", &a, &n);
	v = a;
	while(i <= n) {
		s += v;
		v = v * 10 + a;
		//printf("i:%d, a:%d, %lld\n", i, a, s);
		++i;
	}	

	printf("%lld\n", s);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 1, n = 10;
	long long s = 0;
	long long v = 1;

	while(i <= n) {
		v *= i;
		s += v;
		
		++i;
	}
	printf("%lld\n", s);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int k;
	int n1 = 100, n2 = 50, n3 = 10;
	double d = 0;
	
	k = 1;
	while(k <= n1) {
		d += k;
		++k;
	}
	
	k = 1;
	while(k <= n2) {
		d += (k * k);
		++k;
	}	

	k = 1;
	while(k <= n3) {
		d += (1. / k);
		++k;
	}	

	printf("%.4f\n", d);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i, j, k;

	for(i = 1; i <= 9; ++i) {
		for(j = 0; j <= 9; ++j) {
			for(k = 0; k <= 9; ++k) {
				if(i * i * i + j * j * j + k * k * k == i * 100 + j * 10 + k) {
					printf("%d%d%d ", i, j, k);
				}
			}
		}
	}
	printf("\n");
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 1, n = 1000;

	while(i <= n) {
		int j = i, k = i;
		int m = 1;
		int p = 0;
		int arr[1000] = {0};

		//printf("%d\n", i);
		while(m < j) {
			if(j % m == 0)
				k -= m, arr[p++] = m;
			++m;
		}
		if(k == 0) {
			int k = 0;
			printf("%d:", i);
			while(k < p) {
				printf(" %d", arr[k]);
				++k;
			}
			printf("\n");
		}
		++i;
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n = 20;
	int i1 = 2, j1 = 1;
	int i = 1;
	double s = 0;

	while(i <= n) {
		double t = 1.0 * i1 / j1;	
		int j2 = j1;
		s += t;

		j1 = i1;
		i1 = i1 + j2;
		++i;
	}

	printf("%.4f\n", s);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double t = 100;
	int i = 1;
	int n;
	double s = 0;
	double rebound;

	scanf("%d", &n);
	while(i <= n) {
		s += t;		
		rebound = t / 2;
		if(i != n)
			s += rebound;

		t /= 2;
		++i;
	}

	printf("%.4f %.4f\n", s, rebound);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int s = 1;
	int i = 1;

	scanf("%d", &n);
	
	while(i < n) {
		s = (s + 1) * 2;
		++i;
	}
	printf("%d\n", s);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double a;
	double x1 = 1.0, x2;

	scanf("%lf", &a);
	do {
		x2 = x1;
		x1 = (x2 + a / x2) / 2;

		if(fabs(x1 - x2) < 1e-5)
			break;
	} while(1);

	printf("%.4f\n", x2);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

double f(double x)
{
	return 2 * pow(x, 3) - 4 * x * x + 3 * x - 6;
}

double f1(double x)
{
	return 6 * pow(x, 2) - 8 * x + 3;
}	

int main()
{
	double x = 1.5;
	double x0;

	while(1) {
		x0 = x - f(x) / f1(x);
		if(f(x0) < 1e-5 || fabs(x - x0) < 1e-5)
			break;
		x = x0; 
	}
	printf("%.4f\n", x);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

double f(double x)
{
	return 2 * pow(x, 3) - 4 * x * x + 3 * x - 6;
}

int main()
{
	double x1 = -10, x2 = 10;
	double x;

	do {
		x = (x1 + x2) / 2;
		if(fabs(f(x)) < 1e-6)
			break;
		else if(f(x1) * f(x) < 0)
			x2 = x;
		else if(f(x) * f(x2) < 0)
			x1 = x;
	} while(1);

	printf("%.4f\n", x);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n = 4;
	int i;

	for(i = 1; i <= n; ++i) {
		int j = n - i;
		int k;
		for(k = 1; k <= j; ++k)
			printf(" ");
		for(k = 1; k <= 2 * i - 1; ++k)
			printf("*");
		printf("\n");
	}

	for(i = 1; i <= n - 1; ++i) {
		int j = i;
		int k;
		for(k = 1; k <= j; ++k)
			printf(" ");
		for(k = 1; k <= 2 * (n - j) - 1; ++k)
			printf("*");
		printf("\n");
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i, j, k;

	for(i = 'X'; i <= 'Z'; ++i) {
		for(j = 'X'; j <= 'Z'; ++j) {
			for(k = 'X'; k <= 'Z'; ++k) {
				if(i != 'X' && k != 'X' && k != 'Z' && i != j && j != k && i != k)	
					printf("A %c\n", i), printf("B %c\n", j), printf("C %c\n", k);
			}	
		}
	}	
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int fab[40] = {1, 1};
	int n;
	int i;
	int k = 2;

	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		printf("%12d", fab[i]);
		if((i + 1) % 5 == 0)
			printf("\n");
		if(k < n)
			fab[k] = fab[k - 1] + fab[k - 2], ++k;
	}
	printf("\n");

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void bubble_sort(int a[], int size)
{
	int i, j;

	for(i = 0; i < size - 1; ++i) {
		for(j = size - 1; j > i; --j) {
			if(a[j] < a[j - 1]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

int main()
{
	int a[200];
	int i = 0;
	int n;

	scanf("%d", &n);
	while(i < n) {
		scanf("%d", &a[i++]);
	}

	bubble_sort(a, n);

	for(i = 0; i < n; ++i) {
		printf("%d ", a[i]);	
	}
	printf("\n");

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int m = 3, n = 4;
	int i, j;
	int a[m][n];
	int max;
	int max_i, max_j;

	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	max = a[0][0];
	max_i = max_j = 0;
	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			if(a[i][j] > max)
				max = a[i][j], max_i = i, max_j = j;
		}
	}
	printf("%d %d %d\n", max, max_i, max_j);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int main()
{
	char s[] = "I am a program";
	int size;
	int i;

	size = strlen(s);
	for(i = 0; i < size; ++i)
		putchar(s[i]);

	printf("\n");
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b;
	long long sum;

	scanf("%d%d", &a, &b);
	sum = (long long)a + (long long)b;
	printf("%lld\n", sum);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int m, n;
	
	while(scanf("%d%d", &m, &n) != EOF) {
		int sum = 0;
		while(m != 0) {
			int m1 = m % 10;
			int n0 = n;
			while(n0 != 0) {
				int n1 = n0 % 10;
				sum += m1 * n1;
				n0 /= 10;
			}
			m = m / 10;
		}
		printf("%d\n", sum);
	}

	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	get_eat_methods(int n)
{
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	return get_eat_methods(n - 1) + get_eat_methods(n - 2);
}

int main()
{
	int n;

	while(scanf("%d", &n) != EOF) {
		int methods;
		methods = get_eat_methods(n);
		printf("%d\n", methods);
	}
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a[3][3];
	int i, j;

	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 3; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 3; ++j) {
			printf("%d", a[j][i]);
			if(j < 2)
				printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	printf("%d\n", 0);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	printf("This is my first c program!\n");
	return 0;
}
