#include <iostream>

using namespace std;

int main()
{
	int **mem_arr;
	int i = 0;

	mem_arr = new int*[1024 * 1024 * 1024];
	memset(mem_arr, 0, 1024 * 1024 * 1024);
	while(i < 1024) {
		mem_arr[i] = new int[1024 * 1024 * 1024];
		memset(mem_arr[i], 0, 1024 * 1024 * 1024);
		//mem[256 * 1024 * 1024 - 1] = 1;
		++i;
	}	

	return 0;
}
