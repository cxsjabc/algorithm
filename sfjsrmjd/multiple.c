#include <stdio.h>
#include <string.h>
// has bugs

int num_len(int n)
{
	int i = 1;
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
	//printf("n:%d, s:%s\n", n, s);
	s[0] = '0';
	if(n == 0) {
		s[1] = '\0';
		return;
	}
	while(n > 0) {
		s[i++] = n % 10 + '0';
		//printf("s[%d] = %d\n", i - 1, s[i - 1]);
		n /= 10;
	}
	//printf("s:%s\n", s);
	s[i] = '\0';
	//printf("s:%s\n", s);
	
	// reverse
	for(i = 0; i < len / 2; ++i) {
		char temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 -i] = temp;
	}
	//printf("s:%s\n", s);
}

void reverse_s(char *s)
{
	int len = strlen(s);
	int i = 0;
	while(i < len / 2) {
		char temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 -i] = temp;
		++i;
	}
}

void append_blank(char *s, int blank_count)
{
	int i = 0, len, index;
	len = strlen(s);
	index = len;
	while(i < blank_count) {
		s[index] = ' ';
		++index;
		++i;
	}
	s[index] = '\0';
	//printf("blank_count:%d,s:%s\n", blank_count, s);
}

void move_str_to_end(char *s, char *dest, int dest_len)
{
	int len = strlen(s);
	int i = 0;
	while(i < dest_len - len) {
		dest[i] = ' ';
		++i;
	}
	memmove(dest + (dest_len - len), s, len);
}

// bugs: where is bugs?
// so ugly codes, i don't know how to improve it.
void add_by_str(char *sum, char *str)
{
	int i, j;
	char temp_sum[32], temp_str[32];
	int sum_len = strlen(sum);
	int str_len = strlen(str);
	int sum_index = sum_len - 1;
	int str_index = str_len - 1;
	int advance = 0;
	int temp;
	printf("sum:%s,str:%s\n", sum, str);
	move_str_to_end(sum, temp_sum, sizeof(temp_sum));
	move_str_to_end(str, temp_str, sizeof(temp_str));
	
	printf("temp_sum:%s,temp_str:%s\n", temp_sum, temp_str);

	while(sum_len > 0 && str_len > 0) {
		if(temp_sum[sum_index] == ' ')
			temp_sum[sum_index] = '0';
		if(temp_str[str_index] == ' ')
			temp_str[str_index] = '0';
		temp = advance + temp_sum[sum_index] - '0' + temp_str[str_index] - '0';
		temp_sum[sum_index] = temp % 10 + '0';
		advance = temp / 10;		
		--sum_index;
		--str_index;
		--sum_len;
		--str_len;
	}

	temp = 0;
	while(sum_len > 0) {
		int temp;
		if(temp_sum[sum_index] == ' ')
			temp_sum[sum_index] = '0';
		temp = advance + temp_sum[sum_index] - '0';
		temp_sum[sum_index] = temp % 10 + '0';
		advance = temp / 10;		
		--sum_index;
		--sum_len;
	}
	if(temp > 0)
		temp_sum[sum_index] = temp + '0';
	
	temp = 0;
	while(str_len >= 0) {
		int temp;
		if(temp_str[str_index] == ' ')
			temp_str[str_index] = '0';
		temp = advance + temp_str[str_index] - '0';
		temp_sum[str_index] = temp % 10 + '0';
		advance = temp / 10;
		--str_index;		
		--str_len;
	}
	if(temp > 0)
		temp_sum[str_index] = temp + '0';
	printf("sum:%s\n", temp_sum);
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
	char sum[32] = {0};

	scanf("%d%d", &m, &n);
	printf("%13d\n", m);	
	printf("X%12d\n", n);	
	printf("-------------\n");
	m_len = num_len(m);
	n_len = num_len(n);
	itoa_xi(m, ms);
	itoa_xi(n, ns);
	
	for(i = n_len - 1; i >= 0; --i) {
		for(j = m_len - 1; j >= 0; --j) {
			int temp = remain + (ns[i] - '0') * (ms[j] - '0');
			result[k++] = temp % 10 + '0';
			remain = (temp - temp % 10) / 10;
		}	
		if(remain > 0)
			result[k++] = remain + '0';
		result[k] = '\0';
		//printf("%13s\n", result);
		reverse_s(result);
		//printf("%13s\n", result);
		append_blank(result, n_len - i - 1);	
		add_by_str(sum, result);
		printf("%13s\n", result);
		k = 0;
		remain = 0;
	}
	printf("-------------\n");
	printf("%s\n", sum);

    return 0;
}
