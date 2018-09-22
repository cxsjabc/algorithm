#include "common_local.h"
#include <stack>
#include <iostream>

using namespace std;

int climb1(int n)
{
	int *p;
	int i;
	int ret;

	p = (int *)malloc(sizeof(int) * n);
	assert(p);

	p[0] = 1;
	p[1] = 2;

	for(i = 2; i < n; ++i)
		p[i] = p[i - 1] + p[i - 2];
	ret = p[n - 1];

	free(p);

	return p[n - 1];
}

void show_climb(stack<int> &s, int n)
{
	if(n >= 1) {
		s.push(1);
		show_climb(s, n - 1);
		s.pop();
	}
	
	if(n >= 2) {
		s.push(2);
		show_climb(s, n - 2);
		s.pop();
	}

	if(n == 0) {
		stack<int> temp = s;
		while(!temp.empty()) {
			cout << temp.top();
			temp.pop();	
		}
		cout << endl;
	}
}

int main()
{
	int n;
	stack<int> s;

	while(scanf("%d", &n) == 1) {
		if(n > 0) {
			show_climb(s, n);
		}
	}
    return 0;
}
