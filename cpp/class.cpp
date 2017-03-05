#include <iostream>

using namespace std;

#include "common_local.h"

class B
{
public:
	B()
	{
		cout << "B constructor" << endl;
	}
	B(const B & b)
	{
		cout << "B copy constructor" << endl;
	}

	B &operator=(const B & b)
	{
		cout << "B operator=" << endl;
		return *this;
	}

	~B()
	{
		cout << "~B()" << endl;
	}
};

class A
{
public:
	A() 
	{
		cout << "A constructor" << endl;
	}

	A(const A & a)
	{
		cout << "A copy constructor" << endl;
	}

	A & operator=(const A & a)
	{
		cout << "A operator=" << endl;
		this->i = a.i;
		return *this;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

public:
	void show() const
	{
		cout << "Show:" << i << endl;
	}

private:
	int i;
	B   b;
};


A make_a(A a)
{
	return a;
}

int main()
{
	
	// A a(); // just a function declaration
	A a1;
	A a2 = a1;
	//P_HERE();
	//a2 = a1;	
	
	a1.show();
	a2.show();

	//P_HERE();
	//make_a(a1);

	//P_HERE();

	return 0;
}
