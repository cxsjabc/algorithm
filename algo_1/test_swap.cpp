#include <iostream>
#include "common_local.h"

using namespace std;

// bug: if a, b is the same reference of variable
void swap1(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

int main() 
{
	int a = 3, b = 2;

	swap1(a, a);
	
	cout << a << " " << b << endl;
	return 0;
}
