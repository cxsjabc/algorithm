#include "common_local.h"

void trans()
{
	char buf[128];
	char *s;

	scanf("%s", buf);
	s = buf;

	while(*s) {
		switch(*s) {
			case '1':
				fprintf(stderr, "a");
				++s;
				break;
			case '0':
				++s;
				if(*s == '\0') {
					exit(-1);
					break;
				}
				switch(*s) {
					case '1':
						fprintf(stderr, "b");
						++s;
						break;
					case '0':
						if(*s == '\0') {
							exit(-1);
							break;
						}
						++s;
						if(*s == '\0') {
							exit(-1);
							break;
						}
						if(*s == '1') {
							fprintf(stderr, "c");
							++s;
							break;
						} else {
							exit(-1);
							break;
						}	
						break;
					default:
						exit(-1);
						break;
				}
				break;
			default:
				exit(-1);
				break;
		}	
	}
}

int main()
{
	trans();
    return 0;
}
