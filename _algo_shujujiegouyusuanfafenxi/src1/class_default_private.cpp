#include <iostream>

using namespace std;

class A
{
	int a;
	void show() { cout << "A" << endl; }
};

int main()
{
	A a;
	a.show();

	return 0;
}
