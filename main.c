#include "functions.h"

int main(void) {
	//strcat Driver Code
	char cat[100] = "cat";
	my_str_n_cat(cat, "dog", 2);
	puts(cat);

	//Binary Search Driver Code
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
	printf("%d\n", binary_search(arr, 10, 15));
	return 0;
}