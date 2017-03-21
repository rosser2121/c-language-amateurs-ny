#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "delimiter.h"


int main(int argc, char *argv[]){

	float i = 1200;

	char* in = delimiter_int(i);

	int* len = commafy(in, "int"); 
	
	printf("1: char in = %s\n", in);
	printf("1a: i = %f\n", i);
	printf("1b: len = %d\n", len);


	return 0;
}



// char *str = int_to_str(*i);