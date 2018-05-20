//#include "common_local.h"

#include <iostream>
#include <queue>
#include <vector>
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

void bfs(int g[][N], int s, int e)
{
	int i = 0;
	queue<int> q;
	vector<int> p;
	vector<int>::iterator it;
	int v, ve;

	// mark as not visited
	while(i < N) {	
		visited[i] = 0;
		++i;
	}

	// queue the first node
	q.push(s);
	visited[s] = 1;

	while(!q.empty()) {
		v = q.front();
		q.pop();
		p.push_back(v);
		for(i = 0; i < N; ++i) {
			ve = g[v][i];
			if(ve == 1 && !visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
			// find the end
			if(i == e && visited[i]) {
				p.push_back(i);	
				for(it = p.begin(); it != p.end(); ++it)	
					cout << *it << " ";
				cout << endl;
				return;
			}
		}
	}
}

int main()
{
	bfs(g, 0, 4);
    return 0;
}
