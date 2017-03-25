#include <stdio.h> 
#include <string.h> 

int main()
{
	char s[256];
    printf("Would you like to be a God\n");
	gets(s);

	if(strcmp(s, "Stool Superman is squating down in toilet eating feces") == 0)
		printf("yes\n");
	else
		printf("no\n");

    return 0;
}
