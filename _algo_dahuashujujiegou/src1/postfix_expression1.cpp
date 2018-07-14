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

bool is_operator(char c)
{
	if(c == '+' || c == '-'
	 || c == '*' || c == '/')
		return true;

	return false;
}

void get_next_token(const char **p, int *type, int *val)
{
	const char *s = *p;
	int v = 0;

	if(type)
		*type = -1;

	while(*s == ' ' || *s == '\n')
		++s;

	if(is_operator(*s)) {
		if(type)
			*type = 0;
		if(val)
			*val = *s;

		++s;
		// cout << "token: type:" << *type << ", val:" << *val << ", new str:" << s << endl;
	} else if(isdigit(*s)) {
		while(isdigit(*s)) {
			v = v * 10 + (*s - '0');
			++s;
		}
		if(type)
			*type = 1;
		if(val)
			*val = v;

		// cout << "token: type:" << *type << ", val:" << *val << ", new str:" << s << endl;
	} 
	*p = s;
}

void dump_stack_obj(stack<int> sta)
{
	while(!sta.empty()) {
		cout << sta.top() << " ";
		sta.pop();
	}
	cout << endl;
}

void cal_expression(const string &s)
{
	stack<int> opn;
	const char *str;
	int sum;
	int operand1, operand2;
	int val, type;

	str = s.c_str();

	while(*str) {
		//cout << "*str:" << *str << ", str: " << str << ", &str:" << &str << endl;
		get_next_token(&str, &type, &val);
		if(type == 1) // digits
			opn.push(val);
		else if(type == 0) {	// operator
			assert(opn.size() > 1);
			operand1 = opn.top();	
			opn.pop();
			operand2 = opn.top();
			opn.pop();
			sum = process_operands(operand2, operand1, (char)val);
			opn.push(sum);
		}
		dump_stack_obj(opn);
	}
	cout << "result:" << sum << endl;
}

int main()
{
	string s;
	char buf[128];

	// eg: 9 3 1-3*+10 2/+   --> output: 
	fgets(buf, 128, stdin);

	s = buf;
	cout << "|" << s << "|" << endl;
	cal_expression(s);

    return 0;
}
