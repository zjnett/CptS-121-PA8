#include "functions.h"

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