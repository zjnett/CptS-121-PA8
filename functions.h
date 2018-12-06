/***************************************************
Programmer: Zach Nett
Class: CptS 121 Fall 2018
Date: November 22 2018
Purpose: An implementation of C interview questions.
GitHub Link: https://github.com/zjnett/CptS-121-PA8
****************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

char * my_str_n_cat(char *dest, const char *src, int n); 
int binary_search(int list[], int size, int target);
void bubble_sort(char * arr[], int numStrings);
int is_palindrome(char str[], int length, int hasRemovedSpaces);
int sum_primes(unsigned int n);
int isPrime(unsigned int n);

#endif