#include <stdio.h>

int main(int argc, char const *argv[]){
	
	int ages[] = {35, 29, 12, 42, 33};

	char *names[] = {
		"Marty", "Vicky",
		"Dexter","Katie","Laura"
	};

	// int *agesptr = {35, 29, 12, 42, 33};

	// int **namesptr = {
	// 	"Marty", "Vicky",
	// 	"Dexter","Katie","Laura"
	// };

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	for(i = 0; i < count; i++){
		printf("%s is age %d.\n", names[i], ages[i]);
	}

	printf("---\n");

	// These are the pointers
	int *cur_age = ages;
	//single dimensional array of type interger
	char **cur_name = names;
	//second asterisk is for multidimensional array (of type char)

	for(i = 0; i < count; i++){
		printf("%s is %d years old - the addresses of which are %p and %p\n",  
			*(cur_name + i), *(cur_age + i), &*(cur_name + i), &*(cur_age + i));
	}
	printf("---\n");

	printf("Names address: %p / Ages address: %p\n", &names, &ages);

	printf("---\n");

	for(i = 0; i < count; i++){
		printf("%s is %d years old again - the addresses of which are %p and %p\n", cur_name[i], cur_age[i], &cur_name[i], &cur_age[i]);
	}

	printf("---\n");

	for (cur_name = names, cur_age = ages;
		(cur_age - ages) < count; cur_name++, cur_age++){
		printf("%s has lived %d years so far\n", *cur_name, *cur_age);
	}


	return 0;
}