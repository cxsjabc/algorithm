#include <stdio.h> 

int	get_fish_finder_type(int arr[], int size)
{
	int ret;
	int i = 0;

	if(arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3])
		ret = 1;
	else if(arr[0] > arr[1] && arr[1] > arr[2] && arr[2] > arr[3])
		ret = 2;
	else if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3])
		ret = 3;
	else
		ret = 4;
	return ret;	
}

int main()
{
	int arr[4];
	int i = 0;
	int ret;

	while(i < 4) {
		scanf("%d", &arr[i]);
		++i;
	}
	
	ret = get_fish_finder_type(arr, 4);
	if(ret == 1)
		printf("Fish Rising\n");	
	else if(ret == 2)
		printf("Fish Diving\n");	
	else if(ret == 3)
		printf("Fish At Constant Depth\n");	
	else if(ret == 4)
		printf("No Fish\n");	
    return 0;
}
