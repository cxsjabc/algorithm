/**
*	It's very hard to complete it. You should read it.
**/

#define LOG_LEVEL VERBOSE
#include "common.h"

int less(const char *s, int p, int q)
{
	int len = strlen(s);

	for(int i = 0; i < len; ++i) {
		char sp = s[(p + i) % len]; 
		char sq = s[(q + i) % len]; 
		log_v("len:%d, i:%d, p:%d, sp:%d, q:%d, sq:%c\n", len, i, p, sp , q, sq);
		if(sp != sq)
			return sp < sq;
	}
	return 0;
}

int main()
{
	int T;	// test count
	char s[11] = {0};
	int first = 0;
	
	scanf("%d", &T);
	while(T--) {
		int len;
		int ans = 0;
		char ch;

		//memset(s, 0, 11);
		#if 0
			scanf("%s", s);		// not safe
		#else
		// clear stdin buffer
		// if not clear, fgets will return immediately
		#if 0
		while(1) {
			ch = getchar();
			printf("%d ", ch);
			if(ch == EOF)
				break;
		}
		#endif
		//printf("%d\n", '\n');
		if(first++ == 0) 
			while((ch = getchar()) != '\n' && ch != EOF);		
		#if 0
			while((ch = getchar()) == '\n') ; // bugs here and below
			if(ch != EOF)
				ungetc(ch, stdin);
		#endif

		fgets(s, 11, stdin); // Notice that: it will store '\n'
		if(s[strlen(s) - 1] == '\n')
			s[strlen(s) - 1] = '\0';
	 	#endif
	
		log_v("s:|%s|\n", s);
		ASSERT(s);

		len = strlen(s);
		for(int i = 1; i < len; ++i)
			if(less(s, i, ans)) {
				ans = i;
				log_v("ans:%d\n", ans);
			}

		log_v("Ans:%d\n", ans);
		for(int i = 0; i < len; ++i)
			putchar(s[(ans + i) % len]);
		putchar('\n');
	}
	
    return 0;
}
