#include <stdio.h>
#include <ctype.h>
#include <string.h>

//fwd declarations:

// int can_print_it(char ch);
void print_letters(char word[],int len);


//

void print_letters(char word[],int len){

	int i = 0;
	printf("\"%s\" is %d chars long \n", word, len);
	
	for(i = 0; i < len; i++){
		char ch = word[i];

		if (isalpha(ch)){
			printf("'%c' == %d ", ch, ch);
			// printf("%c",ch);
		}else{
			printf(" ");
		}
	}
	printf("\n");
}

//

void print_arguments(int argc, char *argv[]){
	int i = 0;
	int len = 0;

	for (i = 1; i < argc; i++){
		len = strlen(argv[i]);
		print_letters(argv[i],len);

	}
}

//


// int can_print_it(char ch){
// 	// isalpha and isblank are functions from header file ctype.h
// 	return isalpha(ch) || isblank(ch);
// }

//

int main(int argc, char *argv[]){
	print_arguments(argc, argv);
	return 0;
}