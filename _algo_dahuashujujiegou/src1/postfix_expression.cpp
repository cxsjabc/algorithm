#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

#include "common_local.h"

using namespace std;

int process_operands(int v1, int v2, char ope)
{
	int res;

	switch(ope) {
		case '+':
			res = v1 + v2;
			break;
		case '-':
			res = v1 - v2;
			break;
		case '*':
			res = v1 * v2;
			break;
		case '/':
			res = v1 / v2;
			break;
		default:
			assert(0);
			break;
	}
	return res;	
}

void cal_expression(const string &s)
{
	stack<int> opn;
	const char *str;
	int sum;
	int operand1, operand2;

	str = s.c_str();

	while(*str) {
		if(isdigit(*str))
			opn.push(*str - '0');
		else {	// operator
			assert(opn.size() > 1);
			operand1 = opn.top();	
			opn.pop();
			operand2 = opn.top();
			opn.pop();
			sum = process_operands(operand2, operand1, *str);
			opn.push(sum);
		}

		++str;
	}
	cout << "result:" << sum << endl;
}

int main()
{
	string s;

	// eg: 931-3*+82/+   --> output: 19
	cin >> s;

	cal_expression(s);
    return 0;
}
