#include <iostream>
#include <queue>
#include "common_local.h"

using namespace std;

int main() 
{
	int qq[] = {6, 3, 1, 7, 5, 8, 9, 2, 4};
	queue<int> q1, q2;
	int i;

	for(i = 0; i < sizeof(qq) / sizeof(qq[0]); ++i)
		q1.push(qq[i]);
	
	while(!q1.empty()) {
		q2.push(q1.front());
		q1.pop();
		if(!q1.empty()) {
			q1.push(q1.front());
			q1.pop();
		}
	}

	while(!q2.empty()) {
		cout << q2.front() << " ";
		q2.pop();
	}
	cout << endl;

	return 0;
}
