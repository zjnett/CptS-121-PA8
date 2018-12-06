#include "functions.h"

//Function my_str_n_cat.
//Uses pointer arithmetic to append one string onto another for n characters.
char * my_str_n_cat(char *dest, const char *src, int n) {
	while (*dest != '\0') {
		dest++;
	}
	for (int i = 0; i < n; i++) {
		if (*src == '\0') {
			break;
		} else {
			*dest = *src;
			dest++;
			src++;
		}
	}
	return dest;
}

//Function binary_search.
//In a list of integers, searches for a target value by continually splitting the list in half.
//If the target value is found, it returns the index of that target value in the array.
//Else, it returns -1 (impossible index).
int binary_search(int list[], int size, int target) {
	int left = 1, right = size, targetIndex = -1, mid = 0;
	int found = 0;
	while (!found && left <= right) {
		mid = (left + right) / 2;
		if (list[mid] == target) {
			found = 1;
			targetIndex = mid;
		} else if (target < list[mid]) {
			right = mid - 1;
		} else if (target > list[mid]) {
			left = mid + 1;
		}
	}
	return targetIndex;
}

//Function bubble_sort.
//Takes an array of strings and swaps addresses of strings based on alphabetical ASCII comparisons.
//Smaller ASCII values will "bubble" to the top of the array as it is sorted right-to-left.
void bubble_sort(char * arr[], int numStrings) {
	int markerU = numStrings, markerC = 1, i = 0;
	for (i = 0; i < markerU; i++);
	while (i > 1) {
		markerC = 1;
		while (markerC < markerU) {
			if (*arr[markerC] < *arr[markerC - 1]) {
				char * temp = arr[markerC-1];
				arr[markerC - 1] = arr[markerC];
				arr[markerC] = temp;
			}
			markerC++;
		}
		markerU--;
		for (i = 0; i < markerU; i++);
	}
}


//Function is_palindrome.
//Removes spaces from string, then uses pointer arithmetic to compare the converging value of str[0] (through recursion & pointer arithmetic) and the end of the string.
//If they're ever not the same, then the word is not a palindrome.
//Returns 1 if string is a palindrome, 0 if not.
//Admittedly a more elegant solution to this would be to call an external function to check if the passed in string has spaces,
//and another one to remove those spaces. However, I wanted to keep all assigned sub-problems on this assignment to their own functions.
int is_palindrome(char strOrg[], int length, int hasRemovedSpaces) {
	char str[100];
	int count = 0, i = 0;
	while (count < length && !hasRemovedSpaces) {
		if (strOrg[i] != ' ') {
			str[count] = strOrg[i];
			count++;
		}
		i++;
		if (count == length) {
			str[count] = '\0';
		}
	}

	if (!hasRemovedSpaces) { //first time running through, use str
		if (str[0] == '\0') {
			return 1;
		}

		if (str[0] != str[length - 1]) {
			return 0;
		}

		return is_palindrome(str + 1, length -= 2, 1);
	} else { //use strOrg
		if (strOrg[0] == '\0') {
			return 1;
		}

		if (strOrg[0] != strOrg[length - 1]) {
			return 0;
		}
		return is_palindrome(strOrg + 1, length -= 2, 1);
	}
}

//Function sum_primes.
//That being said about recursion and trying to keep every problem in its own function...
//I'm feeling really lazy.
//Checks if n is prime. If so, adds it to the recursive call that converges downwards from n to 2.
//Eventually returns n, or the sum of the prime numbers.
int sum_primes(unsigned int n) {
	int sum = 0;
	if (n == 2) {
		return n;
	}
	if (isPrime(n)) {
		sum = n;
	}

	return sum_primes(n - 1) + sum;
}

//Function isPrime. (can't you tell when I've named functions/variables and used recommended method/variable names? I really don't know why I hate underscores so much.
//					 ... except in constants/finals/etc.)
//Returns 1 if number n is prime, 0 if not. Essentially divides odd n by every odd number between 3 and n and checks if it is evenly divisible or not.
//If so, obviously it's not prime, so it returns 0.
int isPrime(unsigned int n) {
	if (n % 2 == 0 && n > 2) {
		return 0;
	}
	for (int i = 3; i < n / 2; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

//Function maximum_occurrences.
//Reads in a string. Counts all occurrences of each character in the string, and then determines the maximum of those occurrences.
//Returns value through pointers to a integer and a character, where each corresponding value is kept track of in a parallel array.
//Frequencies are also calculated based on the number of occurrences of each character divided by the total number of characters, and stored in the
//parameter array of Occurrences structures.
void maximum_occurrences(char *str, Occurrences occurArr[], int *max_occurrences, char *ch) {
	int count[26] = { 0 };
	char temp[26] = { '\0' };
	//Note that indices of characters are in the order they appear, kept track of in parallel array temp.
	int next = 0, nextInt = 0, c = 0, hold = 0, total = 0;
	while (*str != '\0') {
		c = 0;
		//100 is an arbitrary hardcoded string length, since total hasn't been calculated yet.
		for (int i = 0; i < 100; i++) {
			if (*str == temp[i]) {
				hold = i;
				c++;
			}
		}
		if (c == 0) {
			temp[next++] = *str;
		} else {
			count[hold] += c;
		}
		total++;
		str++;
	}

	//calculate frequencies
	for (int i = 0; i < sizeof(occurArr) / sizeof(Occurrences); i++) {
		if (count[i] != 0) {
			occurArr[i].num_occurences = count[i] + 1;
			occurArr[i].frequency = (double)(count[i] + 1) / total;
		} else {
			occurArr[i].num_occurences = 1;
			occurArr[i].frequency = 1.0 / total;
		}
	}

	//return
	int max = 0, maxIndex = 0;
	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
			maxIndex = i;
		}
	}

	*max_occurrences = max + 1;
	*ch = temp[maxIndex];
}