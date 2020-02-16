/*
=============================================================================
Name		:	
Author		:
Version		:
Copyright	:
Description	:Given a list of numbers and a number k, 
return whether any two numbers from the list add up to k
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "customStringUtil.h"

static int INPUT_OFFSET = 2;

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  Description of method's or function's input parameter
 * @param  ...
 * @return Description of the return value
 */
int compareInts (const void *a, const void *b){
  const int *da = (const int *) a;
  const int *db = (const int *) b;

  return (*da > *db) - (*da < *db);
}

 /**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  Description of method's or function's input parameter
 * @param  ...
 * @return Description of the return value
 */
int * parseArgV(int arraySize, char *argv[]){
	int *list = malloc((arraySize)*sizeof(int));

	for (int i = 0; i < arraySize; i++){
		list[i]= atoi(argv[i]);
	}

	return list;
}

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  Description of method's or function's input parameter
 * @param  ...
 * @return Description of the return value
 */
char * boolValToString(bool boolean){
	return (boolean ? "True" : "False");
}

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  Description of method's or function's input parameter
 * @param  ...
 * @return Description of the return value
 */
void foundMessage(char* functionName, int a, int b, int k){
	printf("Value found in %s function. %d plus %d add up to %d\n", functionName, a, b, k);
}

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  Description of method's or function's input parameter
 * @param  ...
 * @return Description of the return value
 */
void notFoundMessage(char* functionName){
	printf("No Value found in %s function.\n", functionName);
}

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  Description of method's or function's input parameter
 * @param  ...
 * @return Description of the return value
 */
void outputAnswer(char* functionName, bool boolean){
 	printf("%s output: %s\n", functionName, boolean ? "True" : "False");
}

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  Description of method's or function's input parameter
 * @param  ...
 * @return Description of the return value
 */
bool twoLoops(int arraySize, int k, int *listOfNumber){
	for (int i = 0; i < arraySize; i++){
		for (int j = 0; j < arraySize; j++){
			if(i != j && (listOfNumber[i]+listOfNumber[j] == k)){
				foundMessage("twoLoops", listOfNumber[i], listOfNumber[j], k);
				return true;
			}
		}
	}
		notFoundMessage("twoLoops");

	return false;
}

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  Description of method's or function's input parameter
 * @param  ...
 * @return Description of the return value
 */
bool sortAndBS(int arraySize, int k, int *listOfNumber){
	int searchValue, *matchingValue;
	
	//use mergesort to sort array
	mergesort(listOfNumber, arraySize, sizeof(int), compareInts);

	//conduct binary search
	for (int i = 0; i < arraySize; i++){
		searchValue = k - listOfNumber [i];
		matchingValue = (int*) bsearch (&searchValue, listOfNumber, arraySize, sizeof (int), compareInts);
		
		if(matchingValue != NULL && matchingValue != &listOfNumber[i]){
			foundMessage("sortAndBS", listOfNumber[i], *matchingValue, k);
			return true;
		}
	}
	notFoundMessage("sortAndBS");

	return false;	
}

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  Description of method's or function's input parameter
 * @param  ...
 * @return Description of the return value
 */
bool sortWalkingInwards(int arraySize, int k, int *listOfNumber){
	int lhs = 0, rhs = arraySize - 1;
	
	
    mergesort(listOfNumber, arraySize, sizeof(int), compareInts);

	while (lhs < rhs) {
		int sum = listOfNumber[lhs] + listOfNumber[rhs];
		if (sum == k){
			foundMessage("sortWalkingInwards", listOfNumber[lhs], listOfNumber[rhs], k);
			return true;
		} 

		else if (sum < k) {
			lhs++;
		}

		else {
			rhs--;
		}
	}
	notFoundMessage("sortWalkingInwards");

	return false;
}

int main(int argc, char *argv[]){
	/* Define Variable from problem description*/
	int k = atoi(argv[1]),
	listSize = argc - INPUT_OFFSET,
	*listOfNumber = stringToIntPointer(listSize, &argv[2]);

	clock_t start, end;
    double cpu_time_used;
	bool solution;
	
	//solution 1: two loops O(n^2) time, O(1) space
	start = clock();
	solution = twoLoops(listSize, k, listOfNumber);
	outputAnswer("twoLoops", solution);
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time elapsed for twoLoops %lf\n\n", cpu_time_used);
	
	//solution 2: Hashtable N/A 
	
	//solution 3: Sorting and binary search
	start = clock();
	solution = sortAndBS(listSize, k, listOfNumber);
	outputAnswer("sortAndBS", solution);
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time elapsed for sortAndBS %lf\n\n", cpu_time_used);

	//solution 4: Sorting and Walking Inward
	start = clock();
    solution = sortWalkingInwards(listSize, k, listOfNumber);
    outputAnswer("sortWalkingInwards", solution);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time elapsed for sortWalkingInwards %lf\n\n", cpu_time_used);

    free(listOfNumber);
	
}