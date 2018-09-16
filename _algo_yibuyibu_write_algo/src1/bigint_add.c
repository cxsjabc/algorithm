#include "common_local.h"

// src1/src2: "123" -> means 123, not 321
void	bigint_add(char src1[], int len1, char src2[], int len2, char dest[], int *plen)
{
	int i, j;
	int k, extra;
	int m;

	k = 0, extra = 0;
	for(i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; --i, --j) {
		int temp;
		temp = src1[i] - '0' + src2[j] - '0' + extra;
		dest[k++] = temp % 10 + '0', extra = temp / 10;
	}	
	if(i == -1) {
		for(m = j; m >= 0; --m) {
			int temp;
			temp = src2[j] - '0' + extra;
			dest[k++] = temp % 10 + '0', extra = temp / 10;
		}	
	}
	if(j == -1) {
		for(m = i; m >= 0; --m) {
			int temp;
			temp = src1[i] - '0' + extra;
			dest[k++] = temp % 10 + '0', extra = temp / 10;
		}	
	}
	if(extra > 0)
		dest[k++] = extra + '0';
	for(i = 0; i <= (k - 1) / 2; ++i) {
		char temp = dest[i];
		dest[i] = dest[k - 1 - i];
		dest[k - 1 - i] = temp;
	}
	dest[k] = '\0';
	if(plen)
		*plen = k;
}

int main()
{
	char s1[24], s2[24];
	char dest[128];
	int len;	

	scanf("%s%s", s1, s2);
	bigint_add(s1, strlen(s1), s2, strlen(s2), dest, &len);
    printf("%s\n", dest);
    return 0;
}
