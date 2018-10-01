#include "common_local.h"

#define N	6

static int path[N][N] = 
{
{0, 0, 0, 0, 1, 1},
{1, 1, 0, 0, 1, 0},
{0, 1, 1, 1, 1, 0},
{0, 0, 1, 0, 1, 2}, 
{0, 0, 1, 0, 1, 0}, 
{0, 0, 1, 1, 1, 0}
};

static int value[N][N];

int check_pos_valid(int x, int y)
{
	if(x < 0 || x >= N || y < 0 || y >= N)
		return 0;
	if(value[x][y] == '#')
		return 0;
	if(path[x][y] == 0)
		return 0;

	return 1;
}

void print_path()
{
	int x, y;

	for(x = 0; x < N; ++x) {
		for(y = 0; y < N; ++y) {
			printf("%c", value[x][y] != '#' ? value[x][y] + '0' : '#');
		}
		printf("\n");
	}
	printf("\n");
}

int find_path(int x, int y)
{
	if(check_pos_valid(x, y)) {
		if(2 == path[x][y]) {
			value[x][y] = '#';
			print_path();
			return 1;
		}

		value[x][y] = '#';
		if(find_path(x, y - 1))
			return 1;
		if(find_path(x, y + 1))
			return 1;
		if(find_path(x - 1, y))
			return 1;
		if(find_path(x + 1, y))
			return 1;
		value[x][y] = 0;	
		return 0;
	}

	return 0;
}

int main()
{
	int ret;

	ret = find_path(1, 0);
	PD(ret);

    return 0;
}
