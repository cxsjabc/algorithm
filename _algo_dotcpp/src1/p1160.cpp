#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <iostream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int main()
{
	list<int> l;
	list<int>::iterator it;
	int n, m;
	int k;

loop:
	if(!(cin >> n >> m))
		goto end;
	l.erase(l.begin(), l.end());
	for(int i = 1; i <= n; ++i)
		l.push_back(i);

	it = l.begin();
	while(l.size() > 1) {
		k = m;
		while(k > 1) {
			++it;
			if(it == l.end())
				it = l.begin();
			--k;
		}

		l.erase(it++);
		if(it == l.end())
			it = l.begin();
	}

	if(it == l.end())
		it = l.begin();
	cout << *it << endl;
	goto loop;

end:
	return 0;
}
