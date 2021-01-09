#include<stdio.h>
#include<stdlib.h> 

int getSize (char * s) {
/*  returns size of input string */ 
/*  This function is already complete; you may use it freely. */

    char * t;
    for (t = s; *t != '\0'; t++);
    return t - s;
}

// -------------------------------------
// TODO: Function solutions
//
// See assignment for more detailed 
// information about the purpose and
// operation of the function.
//
// Please remember help is available 
// (TA, LAs, or instructor)
// -------------------------------------

void lab_swap_strings(char* strA, char* strB) {
/* Swaps contents of two character arrays (strings) */
	char temp;    // char variable used in swapping one character at a time

  	for (int i = 0; i < 100; i++) {
    	temp = strA[i];
    	strA[i] = strB[i];
    	strB[i] = temp;
  	}

}

int lab_str_cmp(char* strA, char* strB){

	int i = 0;
	int difference = 0;

	while (difference == 0) {
		if (strA[i] < strB[i]) {
			difference = -1;
		} else if (strA[i] > strB[i]) {
			difference = 1;
		} else if (strA[i] == '\0') {
			break;
		}
		i++;
	}

	return difference;

	return 0;
/* returns               */
/*     1  if strA > strB */
/*     0  if strA = strB */
/*     -1 if strA < strB */
}

void lab_str_upper(char* str){
/* CAPITALIZES STRING s */
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
		i++;
	}
}

void lab_str_lower(char* str){
/* lowercases string s */
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
		i++;
	}
}

float calculateExecutionTime(float cpi, float clockRate) {

	float clockCycle = 1/clockRate;
	float cpuTime = clockCycle * cpi * 10000 / 1000000;

	return cpuTime;
}

int main() {

	// Variables from Lab 2.
    char processors[10][100];
    float costs[10];
    float clockrates[10];
    float cpis[10];
    float executiontimes[10];
	int number_of_processors = 0;
	char sortBy[6];
	float thresholdValue;
	char threshold[6];
	char value[2];


	// Enter in all of the different processors, costs, clock rate and CPI

    printf("Please enter the number of processors [1 to 10]:\n");
    scanf("%d", &number_of_processors );

    for (int i=0; i<number_of_processors; i++ ) {
		printf("Processor Name (no spaces):\n" );
		scanf("%s", processors[i] );
		printf("Processor cost (US dollars):\n" );
		scanf("%f", &costs[i] );
		printf("Processor clock rate (in GHz):\n" );
		scanf("%f", &clockrates[i] );
		printf("Processor average CPI:\n" );
		scanf("%f", &cpis[i] );

		executiontimes[i] = calculateExecutionTime(cpis[i], clockrates[i]);
    }

    printf("Which value would you like to sort on (from lowest to highest)?\n");
 	scanf("%s", sortBy);

 	if (lab_str_cmp(sortBy, "price") == 0) {
 		// sort by costs

 		for (int i = 0; i < number_of_processors; i++) {
 			for (int j = 0; j < number_of_processors; j++) {

 				float temp;

	 			if (costs[i] < costs[j]) {

					lab_swap_strings(processors[i], processors[j]);

	 				temp = executiontimes[i];
	 				executiontimes[i] = executiontimes[j];
	 				executiontimes[j] = temp;

	 				temp = costs[i];
	 				costs[i] = costs[j];
	 				costs[j] = temp;

	 				temp = clockrates[i];
	 				clockrates[i] = clockrates[j];
	 				clockrates[j] = temp;
	 				continue;
	 			} else {
	 				continue;
	 			}
	 		}
	 	}

	 	printf("Would you rather place emphasis on values above or below a certain threshold?\n"); // whatever they answer is what they will be making uppercase
 		scanf("%s", threshold); 

 		printf("What is the threshold value for your comparison?\n");
 		scanf("%f", &thresholdValue);

 		if (lab_str_cmp(threshold, "above") == 0) {
 			for (int i = 0; i < number_of_processors; i++) {
 				if (costs[i] <= thresholdValue) {
 					lab_str_lower(processors[i]);
 					continue;
 				} else {
 					lab_str_upper(processors[i]);
 					continue;
 				}
 			}
 		} else {
 			for (int i = 0; i < number_of_processors; i++) {
 				if (costs[i] >= thresholdValue) {
 					lab_str_lower(processors[i]);
 					continue;
 				} else {
 					lab_str_upper(processors[i]);
 					continue;
 				}
 			}
 		}

 		printf("Your emphasized list of processors is...\n");
 		
 		for (int i = 0; i < number_of_processors; i++) {
 			printf("%s\n", processors[i]);
 		}

 	} else if (lab_str_cmp(sortBy, "rate") == 0) {
 		// sort by clock rates

 		for (int i = 0; i < number_of_processors; i++) {
 			for (int j = 0; j < number_of_processors; j++) {

 				float temp;

 				if (clockrates[i] < clockrates[j]) {
 					lab_swap_strings(processors[i], processors[j]);

					temp = executiontimes[i];
	 				executiontimes[i] = executiontimes[j];
	 				executiontimes[j] = temp;

	 				temp = costs[i];
	 				costs[i] = costs[j];
	 				costs[j] = temp;

	 				temp = clockrates[i];
	 				clockrates[i] = clockrates[j];
	 				clockrates[j] = temp; 
	 				continue;
 				} else {
 					continue;
 				}
 			}
 		}

 		printf("Would you rather place emphasis on values above or below a certain threshold?\n"); // whatever they answer is what they will be making uppercase
 		scanf("%s", threshold); 

 		printf("What is the threshold value for your comparison?\n");
 		scanf("%f", &thresholdValue);

 		if (lab_str_cmp(threshold, "above") == 0) {
 			for (int i = 0; i < number_of_processors; i++) {
 				if (clockrates[i] <= thresholdValue) {
 					lab_str_lower(processors[i]);
 					continue;
 				} else {
 					lab_str_upper(processors[i]);
 					continue;
 				}
 			}
 		} else {
 			for (int i = 0; i < number_of_processors; i++) {
 				if (clockrates[i] >= thresholdValue) {
 					lab_str_lower(processors[i]);
 					continue;
 				} else {
 					lab_str_upper(processors[i]);
 					continue;
 				}
 			}
 		}

 		printf("Your emphasized list of processors is...\n");

 		for (int i = 0; i < number_of_processors; i++) {
 			printf("%s\n", processors[i]);
 		}

 	} else if (lab_str_cmp(sortBy, "time") == 0) {
 		// sort by execution times

 		for (int i = 0; i < number_of_processors; i++) {
 			for (int j = 0; j < number_of_processors; j++) {

 				float temp;

	 			if (executiontimes[i] < executiontimes[j]) {

					lab_swap_strings(processors[i], processors[j]);

	 				temp = executiontimes[i];
	 				executiontimes[i] = executiontimes[j];
	 				executiontimes[j] = temp;

	 				temp = costs[i];
	 				costs[i] = costs[j];
	 				costs[j] = temp;

	 				temp = clockrates[i];
	 				clockrates[i] = clockrates[j];
	 				clockrates[j] = temp;

	 				continue;
	 			} else {
	 				continue;
	 			}
	 		}
	 	}

	 	printf("Would you rather place emphasis on values above or below a certain threshold?\n"); // whatever they answer is what they will be making uppercase
 		scanf("%s", threshold); 

 		printf("What is the threshold value for your comparison?\n");
 		scanf("%f", &thresholdValue);

 		if (lab_str_cmp(threshold, "above") == 0) {
 			for (int i = 0; i < number_of_processors; i++) {
 				if (executiontimes[i] <= thresholdValue) {
 					lab_str_lower(processors[i]);
 					continue;
 				} else {
 					lab_str_upper(processors[i]);
 					continue;
 				}
 			}
 		} else {
 			for (int i = 0; i < number_of_processors; i++) {
 				if (executiontimes[i] >= thresholdValue) {
 					lab_str_lower(processors[i]);
 					continue;
 				} else {
 					lab_str_upper(processors[i]);
 					continue;
 				}
 			}
 		}

 		printf("Your emphasized list of processors is...\n");

 		for (int i = 0; i < number_of_processors; i++) {
 			printf("%s\n", processors[i]);
 		}

 	} else if (lab_str_cmp(sortBy, "name") == 0) {
 		// sort by name

 		for (int i = 0; i < number_of_processors; i++) {
 			for (int j = 0; j < number_of_processors; j++) {

 				float temp;

 				if (lab_str_cmp(processors[i], processors[j]) == -1) {

 					lab_swap_strings(processors[i], processors[j]);

	 				temp = executiontimes[i];
	 				executiontimes[i] = executiontimes[j];
	 				executiontimes[j] = temp;

	 				temp = costs[i];
	 				costs[i] = costs[j];
	 				costs[j] = temp;

	 				temp = clockrates[i];
	 				clockrates[i] = clockrates[j];
	 				clockrates[j] = temp;

	 				continue;
 				} else {
 					continue;
 				}


 			}
 		}

		printf("Would you rather place emphasis on values above or below a certain threshold?\n"); // whatever they answer is what they will be making uppercase
 		scanf("%s", threshold); 

 		printf("What is the threshold value for your comparison?\n");
 		scanf("%s", value);

 		if (lab_str_cmp(threshold, "above") == 0) {
 			for (int i = 0; i < number_of_processors; i++) {
 				if (lab_str_cmp(processors[i], value) == 1 || lab_str_cmp(processors[i], value) == 0) {
 					lab_str_lower(processors[i]);
 					continue;
 				} else {
 					lab_str_upper(processors[i]);
 					continue;
 				}
 			}
 		} else {
 			for (int i = 0; i < number_of_processors; i++) {
 				if (lab_str_cmp(processors[i], value) == -1 || lab_str_cmp(processors[i], value) == 0) {
 					lab_str_upper(processors[i]);
 					continue;
 				} else {
 					lab_str_lower(processors[i]);
 					continue;
 				}
 			}
 		}

 		printf("Your emphasized list of processors is...\n");
 		
 		for (int i = 0; i < number_of_processors; i++) {
 			printf("%s\n", processors[i]);
 		}

 	}



    // -------------------------------------
	// TODO: Program solution 
	//
	// See assignment for instructions and 
	// input/output formatting.
	//
	// Please remember help is available 
	// (TA, LAs, or instructor)
	// -------------------------------------

    return 0;

}


