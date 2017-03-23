#include <iostream>

using namespace std;

class No_Inherit_Class
{
private:
	No_Inherit_Class() {}
	~No_Inherit_Class() {}
};


class Class_XXX : public No_Inherit_Class
{
};

int main()
{
	Class_XXX obj;		// if no instanlize, no compile error!
	return 0;
}
