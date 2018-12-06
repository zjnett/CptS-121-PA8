#include "functions.h"

int main(void) {
	printf("************* PA8 DRIVER CODE: *************\n");
	//strcat Driver Code
	char cat[100] = "cat";
	my_str_n_cat(cat, "dog", 2);
	printf("cat + 2 characters of dog = ");
	puts(cat);

	//Binary Search Driver Code
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
	printf("Index of 15 in array: %d\n", binary_search(arr, 10, 15));
	printf("Index of 400 in array: %d (not found)\n", binary_search(arr, 10, 400));

	//Bubble Sort Driver Code
	char w1[5] = "cat";
	char w2[5] = "dog";
	char w3[5] = "bird";
	char w4[5] = "fish";
	int * list[4] = { w1, w2, w3, w4 };

	//Prints list prior to sort
	printf("Unsorted List:\n");
	for (int i = 0; i < 4; i++) {
		puts(list[i]);
	}

	bubble_sort(list, 4);
	
	//Prints list after sort
	printf("Sorted List:\n");
	for (int i = 0; i < 4; i++) {
		puts(list[i]);
	}

	//Palindrome Driver Code
	printf("Is 'r ac  ec ar' a palindrome: %s\n", is_palindrome("r ac  ec ar", 7, 0) ? "true" : "false");
	printf("Is 'ticocat' a palindrome: %s\n", is_palindrome("ticocat", 7, 0) ? "true" : "false");

	//Prime Driver Code
	printf("Sum of primes from 2 to 10: %d\n", sum_primes(10));

	//Max Occurrences Driver Code
	Occurrences array[10];
	int occurrences = 0;
	char ch = '\0';
	maximum_occurrences("test string", array, &occurrences, &ch);
	printf("%c has maximum occurrences in string 'test string', with %d occurrences.\n", ch, occurrences);
	maximum_occurrences("apples", array, &occurrences, &ch);
	printf("%c has maximum occurrences in string 'apples', with %d occurrences.\n", ch, occurrences);

	return 0;
}