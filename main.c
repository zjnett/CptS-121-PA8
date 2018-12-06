#include "functions.h"

int main(void) {
	//strcat Driver Code
	char cat[100] = "cat";
	my_str_n_cat(cat, "dog", 2);
	puts(cat);

	//Binary Search Driver Code
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
	printf("%d\n", binary_search(arr, 10, 15));

	//Bubble Sort Driver Code
	char w1[5] = "cat";
	char w2[5] = "dog";
	char w3[5] = "bird";
	char w4[5] = "fish";
	int * list[4] = { w1, w2, w3, w4 };

	//Prints list prior to sort
	for (int i = 0; i < 4; i++) {
		puts(list[i]);
	}

	bubble_sort(list, 4);
	
	//Prints list after sort
	for (int i = 0; i < 4; i++) {
		puts(list[i]);
	}

	//Palindrome Driver Code
	printf("Is palindrome: %s\n", is_palindrome("r ac  ec ar", 7, 0) ? "true" : "false");

	//Prime Driver Code
	printf("Sum of primes from 2 to 10: %d\n", sum_primes(10));

	return 0;
}