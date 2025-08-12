#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float compute_arr(char arr[3][100]) 
{
	//check the seccond string in the array to find which opperation to perform on the two numbers

	float result; //local variable to stor reslut of calculation

	if(strcmp(arr[1], "+") == 0) //check for + opperator
	{
	 	result = atof(arr[0]) + atof(arr[2]); //convert strings to floats, compute and return results
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

void input(char arr[3][100])
{
	//parse input to an array with 3 strings each 100 characters long
	char *n=malloc(500); //allcocate memory for initial string with size 500
	int i = 0; //initilise counter

	printf(">"); 
	fgets(n, 500, stdin); //get input

	n[strcspn(n, "\n")] = 0; //remove newline characters
	char *ptr = strtok(n, " "); //use strtok to seperate the string
	while(ptr != NULL) { //loop while strtok's pointer is not NULL ei, there is nothing more to seperate
		strcpy(arr[i], ptr); //copy the seperated sub-strings to the corresponding slot in the array
		ptr = strtok(NULL, " "); //run strtok again on same string
		i++; //increment i
	}
	free(n); //free the memory allocated as it is no longer needed
}

int main(int argc, char *argv[]) {
	char a[3][100]; //make a char array with 3 strings each 100 characters long
	float r; //initilise a result variable

	//test if the program name was the only argument
	if (argc == 1) 
	{ 
		input(a); //gets input
		r = compute_arr(a); //compute the result
		printf("=%.3f\n", r); //print the result
	}

	//test whether 4 arguments are given eg: calc 4 + 3
	//					  ^   ^ ^ ^
	//					  1   2 3 4
	else if (argc == 4) 
	{
		//copy the argument strings to an the array initilized at the start of main
		strcpy(a[0], argv[1]);
		strcpy(a[1], argv[2]);
		strcpy(a[2], argv[3]);
		r = compute_arr(a); //compute the array
		printf("=%.3f\n", r); //print the results
	}


	//print help page
	else if (argc == 2 && strcmp(argv[1], "-h") == 0)
	{
		printf("HELP PAGE\n");
		printf("proper useage:\ncalc\ncalc 2 + 6\n");
	}

	//if too many arguments are given then print help page
	else if (argc >=5) 
	{
		printf("TOO MANY ARGUMENTS\n");
		printf("HELP PAGE:\n");
		printf("proper useage:\ncalc\ncalc 2 + 6\n");
	}

	return 0;
}
