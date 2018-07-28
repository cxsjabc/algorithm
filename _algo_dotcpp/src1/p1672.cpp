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

#define	N		100
/* #define DEBUG */

typedef struct 
{
	int x;
	int y;
	int step;
}POS;

char map[N][N];
int visit[N][N];
POS pos_start, pos_end;
int row, col;

void input_arr(char map[N][N], int m, int n)
{
	int i, j;
	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			scanf("%c", &map[i][j]);
			if(map[i][j] == '\n')
				scanf("%c", &map[i][j]);
			if(map[i][j] == 'S')
				pos_start.x = i, pos_start.y = j, pos_start.step = 0;
			if(map[i][j] == 'E')
				pos_end.x = i, pos_end.y = j;
		}
	}
}

POS	get_next(POS pos_start, int i)
{
	POS next = pos_start;
	if(i == 0)
		next.x--;
	else if(i == 1)
		next.x++;
	else if(i == 2)
		next.y--;
	else
		next.y++;
	return next;
}

bool is_pos_end(POS pos)
{
	return pos.x == pos_end.x && pos.y == pos_end.y;
}

bool is_valid(POS pos)
{
	return (pos.x >= 0 && pos.x < row && pos.y >= 0 && pos.y < col 
		  && map[pos.x][pos.y] != '#' && visit[pos.x][pos.y] == 0);
}

int bfs(POS pos_start)
{
	queue<POS> q;
	POS temp;

	q.push(pos_start);
	visit[pos_start.x][pos_start.y] = 1;

	while(!q.empty()) {
		temp = q.front();
	#ifdef DEBUG	
		cout << temp.x << "," << temp.y << endl;
	#endif	
		for(int i = 0; i < 4; ++i) {
			POS next = get_next(temp, i);
			next.step = temp.step + 1;
		#ifdef DEBUG
			cout << next.x << "," << next.y << endl;
		#endif

			if(is_pos_end(next)) {
			#ifdef DEBUG	
				cout << "\tend!" << endl;
			#endif	
				q.push(next);
				visit[next.x][next.y] = 1;
				return next.step;
			} else if(!is_valid(next)) {
			#ifdef DEBUG
				cout << "\t" << "invalid\n"; 
			#endif	
				continue;
			} else {
				q.push(next);
				visit[next.x][next.y] = 1;
			}
		}
		q.pop();
	}
	return -1;
}

int main()
{
	int n;
	
	INPUT(n);
	while(n--) {
		int m, n;

		INPUT2(m, n);
		row = m, col = n;
		input_arr(map, m, n);
		memset(visit, 0, sizeof(visit) / sizeof(visit[0]) * sizeof(int));

		cout << bfs(pos_start) << endl;
	}

	return 0;
}
