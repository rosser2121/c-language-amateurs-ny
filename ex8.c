#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if(argc == 1){
		printf("You've only got one argument.You suck.\n");
	} else if (argc > 1 && argc < 4){
		printf("\nHere's your arguments\n");

		for(i = 1; i < argc; i++){
			printf("%s \n", argv[i]);
		}
		printf("\n");
	} else{
		printf("You've got too many arguments. You suck.\n");
	}

	return 0;
}