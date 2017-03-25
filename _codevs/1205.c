#include <stdio.h> 
#include <string.h> 

void	reverse_words(const char *s, char *d)
{
	int len = strlen(s);
	int i;
	int last = len - 1;
	int k = 0;

	for(i = len - 1; i >= 0; --i) {
		if(s[i] == ' ') {
			// copy the word to str: d
			int j = i + 1;
			while(j <= last)
				d[k++] = s[j++];
			d[k++] = ' ';
			last = i - 1;
		}
		if(i == 0) {
			int j = i;
			while(j <= last)
				d[k++] = s[j++];
			d[k] = '\0';
		}
	}
}

int main()
{
	char s[128], d[128];
	gets(s);

	reverse_words(s, d);
	printf("%s\n", d);	

    return 0;
}
