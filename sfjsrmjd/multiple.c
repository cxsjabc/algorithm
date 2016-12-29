#include <stdio.h>
#include <string.h>
// has bugs

int num_len(int n)
{
	int i = 0;
	while(n > 0) {
		n /= 10;
		++i;
	}
	return i;
}

void itoa_xi(int n, char *s)
{
	int i = 0;
	int len = num_len(n);
	printf("n:%d, s:%s\n", n, s);
	s[0] = '0';
	if(n == 0) {
		s[1] = '\0';
		return;
	}
	while(n > 0) {
		s[i++] = n % 10 + '0';
		printf("s[%d] = %d\n", i - 1, s[i - 1]);
		n /= 10;
	}
	printf("s:%s\n", s);
	s[i] = '\0';
	printf("s:%s\n", s);
	
	// reverse
	for(i = 0; i < len / 2; ++i) {
		char temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 -i] = temp;
	}
	printf("s:%s\n", s);
}

void reverse_s(char *s)
{
	int len = strlen(s);
	int i = 0;
	while(i < len / 2) {
		char temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 -i] = s[i];
		++i;
	}
}

int main()
{
	int m, n;
	int i;
	int m_len, n_len;
	char ms[32], ns[32];
	char result[32];
	int k = 0;
	int remain = 0;
	int j;

	scanf("%d%d", &m, &n);
	printf("%13d\n", m);	
	printf("X%12d\n", n);	
	printf("-------------\n");
	m_len = num_len(m);
	n_len = num_len(n);
	itoa_xi(m, ms);
	itoa_xi(n, ns);
	
	for(i = 0; i < n_len; ++i) {
		for(j = 0; j < m_len; ++j) {
			int temp = remain + (ns[i] - '0') * (ms[j] - '0');
			result[k++] = temp % 10 + '0';
			remain = (temp - temp % 10) / 10;
		}	
		result[k] = '\0';
		reverse_s(result);
		printf("%13s\n", result);
		k = 0;
		remain = 0;
	}

    return 0;
}
