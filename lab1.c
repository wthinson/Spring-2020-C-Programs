#include <stdio.h>

int main( int argc, char** argv ) {

	float i,j,k,l;
	// -------------------------------------
	// TODO: Put your solution here
	//
	// See assignment for instructions and 
	// input/output formatting.
	//
	// Please remember help is available 
	// (TA, LAs, or instructor)
	// -------------------------------------

	printf("Please select the computation you want to make: (1 = clock rate, 2 = CPU time): ");

	scanf("%f", &i);

	if (i == 1) {

		printf("You selected clock rate, please enter the duration of one clock cycle in seconds: ");
		scanf("%f", &j);

		float clockRate = 1 / j;

		printf("The clock rate corresponding to this duration is: %.1f Hertz.\n", clockRate);

	} else {

		printf("You selected CPU time, please enter the duration of one clock cycle in seconds: ");
		scanf("%f", &j);

		printf("You selected CPU time, please enter the number of instructions in the program: ");
		scanf("%f", &k);

		printf("You selected CPU time, please enter the number of clock cycles per instruction: ");
		scanf("%f", &l);

		float cpuTime = j*k*l;

		printf("The CPU execution time corresponding to these parameters is: %.1f seconds.", cpuTime);

	}


	return 0;

}