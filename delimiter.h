#include <string.h>

#ifndef _delimiter_h
#define _delimiter_h
	
	//Thousand length = 7-9;
	//Insert comma @ len - 6
	//Million Length = 10-13;

	char str_float[50];
	char str_int[50];
	char str[50];
	char type[50];
	// char comma = ",";
	char prefix[50];
	// char suffix[50];
	char output[60];


	char* delimiter_float(float num){
		snprintf(str_float, 50, "%.2f", num);
		// type = "float";
		return str_float;
	}

	char* delimiter_int(int num){
		snprintf(str_int, 50, "%d", num);
		// type = "int";
		return str_int;
	}

	// printf("%d", *spoilt1);

	char* commafy(char *str, char *type){
		if (strlen(str) > 3){
			strcopy(prefix, str[0]);
			snprintf(output, 50, "%s,%s%s%s", prefix, str[1], str[2], str[3]);
			return output;

		}else{
			return 0;
		}
	}  

#endif