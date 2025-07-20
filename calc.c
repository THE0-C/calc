#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float compute(char arr[3][100]) {
	//check the seccond string in the array to find which opperation to perform on the two numbers

	float result; //local variable to stor reslut of calculation

	if(strcmp(arr[1], "+") == 0) //check for + opperator
	{
	 	result = atof(arr[0]) + atof(arr[2]); //convert strings to numbers, compute and return results
		return(result); 
	}
	else if(strcmp(arr[1], "-") == 0) //check for - opperator
	{
		result = atof(arr[0]) - atof(arr[2]);
		return(result); 
	}
	else if(strcmp(arr[1], "*") == 0) //check for * opperator
	{
		result = atof(arr[0]) * atof(arr[2]);
		return(result); 
	}
	else if(strcmp(arr[1], "/") == 0) //check for / opperator
	{
		result = atof(arr[0]) / atof(arr[2]);
		return(result); 
	}
	else if(strcmp(arr[1], "+") != 0 && strcmp(arr[1], "-") != 0 && strcmp(arr[1], "*") != 0 && strcmp(arr[1], "/") != 0) //check whether any ilegal opperators were used
	{
		printf("Please only use: +, -, *, / as operators\n"); //advise user on which opparators are legal
		return 0;
	}
}

void input(char arr[3][100]){
	//parse input to an array with 3 strings each 100 characters long
	char *n=malloc(sizeof(500)); //allcocate memory for initial string with size 500
	char *f; //variable to store seperated strings
	int i = 0; //initilise counter

	printf(">"); 
	fgets(n, 500, stdin); //get input

	n[strcspn(n, "\n")] = 0; //remove newline characters
	while((f = strsep(&n, " ")) != NULL) { //loop while strsep does not retrun NULL ei, there is nothing more to sepereate and the end of the string has been reached
		strcpy(arr[i], f); //copy the seperated sub-strings to the corresponding slot in the array
		i++; //increment i
	}
	free(n); //free the memory allocated as it is no longer needed
}

int main(int argc, char *argv[]) {
	char a[3][100]; //make a char array with 3 strings each 100 characters long
	float r; //initilise a result variable

	if (argc == 1) { //test if the program name was the only argument
		input(a); //gets input
		r = compute(a); //compute the result
		printf("=%.3f\n", r); //print the result
	}
	//test whether 4 arguments are given eg: calc 4 + 3
	//					  ^   ^ ^ ^
	//					  1   2 3 4
	else if (argc == 4) {
		//copy the argument strings to an the array initilized at the start of main
		strcpy(a[0], argv[1]);
		strcpy(a[1], argv[2]);
		strcpy(a[2], argv[3]);
		r = compute(a); //compute the array
		printf("=%.3f\n", r); //print the results
	}
	//print help page
	//currently BROKEN
	else if (argc == 2 && strcmp(argv[1], "-h") == 0){
		printf("HELP PAGE\n");
		printf("proper useage: calc, calc 2 + 6\n");
	}
	//if too many arguments are given then print help page
	else if (argc >=5) {
		printf("HELP PAGE\n");
		printf("proper useage: calc, calc 2 + 6\n");
	}

	return 0;
}
