#include <iostream>
#include "common_local.h"

using namespace std;


class Temp
{
public:
	Temp() { ++N; sum += N; }

public:
	static int N;
	static int sum;
};

int Temp::N = 0;
int Temp::sum = 0;

int main() 
{
	Temp *p = new Temp[100];
	PN(Temp::sum);
	delete []p;

	return 0;
}
