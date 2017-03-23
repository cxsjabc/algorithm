#include <iostream>
#include "common_local.h"

using namespace std;

int main() 
{
	int n = 0xFFFEFDFC;
	print_by_byte(&n, sizeof(int));

	return 0;
}
