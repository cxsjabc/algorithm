#include <iostream>

using namespace std;

class Person
{
public:
	Person(int age = 0) { this->age = age; }
	~Person() { cout << "Person " << this << " Desconstruct!" << endl; } 

	void show() const { cout << "Per:" << this << ": age:" << age << endl; }
private:
	int age;
};

int main()
{
	Person *p1, *p2;

	p1 = new Person(12);
	p2 = new Person(22);

	p1->show();
	*p1 = *p2;
	p1->show();

	delete p2;
	delete p1;
	return 0;
}
