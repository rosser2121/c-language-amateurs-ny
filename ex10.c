#include <stdio.h>

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("ERROR: You only need one argument\n");
		return 1;
	}

	int i = 0;
	for (i = 0; argv[1][i] != '\0'; i++){
		char letter = argv[1][i];

		switch (letter){
			case 'a':
			case 'A':
			printf("%d: 'A is a vowel'\n", i);
			break;

			case 'e':
			case 'E':
			printf("%d: 'E is a vowel'\n", i);
			break;

			case 'i':
			case 'I':
			printf("%d: 'I is a vowel'\n", i);
			break;

			case 'o':
			case 'O':
			printf("%d: 'O is a vowel'\n", i);
			break;

			case 'u':
			case 'U':
			printf("%d: 'U is a vowel'\n", i);
			break;

			case 'y':
			case 'Y':
			if(i > 2){
				printf("%d: Y is a vowel... This time\n", i);
				break;
			} else {
				printf("%d: %c is not a vowel\n", i, letter );
				break;
			}
			

			default:
				printf("%d: %c is not a vowel\n", i, letter );

		}
	}

	return 0;
}