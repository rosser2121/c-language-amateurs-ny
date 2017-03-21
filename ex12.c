#include <stdio.h>
#include 

int main(int argc, char *argv[]){
	char full_name[] = {
		'F', 'a', 'k',
		' ', 'U', ' ',
		'L','o','l','z','\0'
	};

	int areas[] = {100, 12, full_name[2], 14, 20};
	char name[] = "Fak";
	

	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n", sizeof(areas));
	printf("The number of ints in areas: %ld\n", 
		sizeof(areas) / sizeof(int));



	printf("The size of name (char[]) %ld\n", sizeof(name));

	printf("The first area is %d, the 2nd is %d.\n", areas[0], areas[1]);

	printf("The size of full name (char[]): %ld\n", sizeof(full_name));

	printf("The number of chars: %ld\n", 
		sizeof(full_name) / sizeof(char));

	printf("name=\"%s\" and full name=\"%s\"\n", name, full_name);

	return 0;
}