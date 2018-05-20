//#include "common_local.h"

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

#define N		5

int g[N][N] = {
	{-1, 1,  1,  1,  0},
	{1, -1,  1,  0,  0},
	{1,  1, -1,  1,  1},
	{1,  0,  1, -1,  1},
	{0,  0,  1,  1, -1},
};

int visited[N];

/* bugs! */
void dfs(int g[][N], int s, int e)
{
	int i = 0;
	stack<int> q;
	vector<int> p;
	vector<int>::iterator it;
	int v, ve;
	bool is_push;

	// mark as not visited
	while(i < N) {	
		visited[i] = 0;
		++i;
	}

	// queue the first node
	q.push(s);
	visited[s] = 1;

	while(!q.empty()) {
		v = q.top();
		//q.pop();
		is_push = false;
		p.push_back(v);

		for(i = 0; i < N; ++i) {
			ve = g[v][i];
			if(ve == 1 && !visited[i]) {
				q.push(i);
				visited[i] = 1;
				is_push = true;
				break;
			}
		}
		// find the end
		if(i == e && visited[i]) {
			p.push_back(i);	
			for(it = p.begin(); it != p.end(); ++it)	
				cout << *it << " ";
			cout << endl;
			return;
		}
		// not found, just delete the node
		if(!is_push)
			p.pop_back();
	}

}

int main()
{
	dfs(g, 0, 4);
    return 0;
}
