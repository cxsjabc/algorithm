#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	Vector<int> v(2);

	for(int i = 0; i < 10; ++i)
		v.push_back(i);

	v.pop_back();	
	v.pop_back();	

	Vector<int>::iterator it = v.begin();

	while(it != v.end()) {
		cout << *it;
		++it;
	}
	cout << endl;

	return 0;
}
