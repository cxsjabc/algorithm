#include "common_local.h"

int	get_same_elements_on_arr(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3)
{
	int i = 0, j = 0, k = 0;
	int last;
	int first_same = 0;
	while(i < size1 && j < size2) {
		if(arr1[i] == arr2[j]) {
			if(!first_same) {
				first_same = 1, last = arr1[0], k < size3 ? arr3[k++] = last : 0;
				++i, ++j;
			} else {
				if(arr1[i] == last)
					++i, ++j;
				else
					last = arr1[i], k < size3 ? arr3[k++] = last : 0, ++i, ++j;
			}
		} else {
			if(arr1[i] < arr2[j])
				++i;
			else
				++j;
		}
	}
	return k;	
}

int main()
{
	int arr1[10], arr2[10] = {0}, arr3[20];
	int ret;
#if 0
	gen_sorted_arr(arr1, 10);
	sleep(3);
	gen_sorted_arr(arr2, 10);

	print_arr(arr1, 10);
	show_arr(arr2, 10);

	PD(is_arr_sorted(arr1, 10));
	PD(is_arr_sorted(arr2, 10));
#endif

	gen_basic_sorted_arr(arr1, 10, 1, 10);
	gen_basic_sorted_arr(arr2, 10, 1, 10);
	print_arr(arr1, 10);
	print_arr(arr2, 10);
	PD(is_arr_sorted(arr1, 10));
	PD(is_arr_sorted(arr2, 10));

	ret = get_same_elements_on_arr(arr1, 10, arr2, 10, arr3, 20);
	PD(ret);
	print_arr(arr3, ret);

    return 0;
}
