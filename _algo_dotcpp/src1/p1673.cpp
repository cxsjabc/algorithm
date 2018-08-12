#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void show_list(list<int> & l) 
{
	list<int>::iterator it;
	for(it = l.begin(); it != l.end(); ++it) {
		cout << *it;
		if(++it != l.end())
			cout << " ";
		--it;
	}
	cout << endl;
}

void merge_list(list<int> &la, list<int> &lb)
{
	list<int>::iterator it;

	show_list(la);	
	show_list(lb);
	for(it = lb.begin(); it != lb.end(); ++it) {
		list<int>::iterator temp;

		temp = std::find(la.begin(), la.end(), *it);	
		if(temp == la.end()) {
			la.push_back(*it);
		}
		show_list(la);
	}
	cout << endl;
}

int main()
{
	list<int> la, lb;
	int m, n;
	int temp;

	while(cin >> m) {
		la.clear();
		lb.clear();
		while(m--) {
			cin >> temp;
			la.push_back(temp);
		}
		cin >> n;
		while(n--) {
			cin >> temp;
			lb.push_back(temp);
		}
		merge_list(la, lb);
	}
	return 0;
}
