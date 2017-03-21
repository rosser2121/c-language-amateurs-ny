#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "delimiter.h"
#include "str_line.h"
#include "dbg.h"

#define MAX_DATA 100

typedef enum PaintColor{
	BLUE_PAINT, GREEN_PAINT, RED_PAINT,
	BLACK_PAINT, OTHER_PAINT
} PaintColor;

const char *PAINT_COLOR_NAMES[] = {
	"Blue", "Green", "Red", "Black", "Other"
};

typedef struct Car {
	int year;
	char marque[MAX_DATA];
	char model[MAX_DATA];
	PaintColor paint;
	float price;
} Car;




//

int main(int argc, char *argv[]){

	Car your_car = {.price = 0};
	int i = 0;
	char *in = NULL;

	printf("What's your car's marque? ");
	in = fgets(your_car.marque, MAX_DATA - 1, stdin);
	in = End_line(in);
	check(in != NULL, "Failed to read car marque.");

	printf("What's your car's model? ");
	in = fgets(your_car.model, MAX_DATA - 1, stdin);
	in = End_line(in);
	check(in != NULL, "Failed to read car model.");

	printf("What year is your car's model? ");
	int rc = fscanf(stdin, "%d", &your_car.year);

	printf("What color is the paint?\n");
	for(i = 0; i <= OTHER_PAINT; i++){
		printf("%d) %s\n", i + 1, PAINT_COLOR_NAMES[i]);
	}
	printf("> ");

	int paint = -1;
	rc = fscanf(stdin, "%d", &paint);
	check(rc > 0, "You have to enter a number.");

	your_car.paint = paint -1;
	check(your_car.paint <= OTHER_PAINT
		&& your_car.paint >= 0, "That's not an option.");

	printf("How much did the car cost? ");
	rc = fscanf(stdin, "%f", &your_car.price);
	check(rc > 0, "Enter a floating point number");

	printf("So your car is a %s '%d %s %s which cost $%.2f \n", PAINT_COLOR_NAMES[your_car.paint], your_car.year, your_car.marque, your_car.model, your_car.price);

	return 0;
error:

	return -1;
}




