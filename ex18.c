#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
	if (errno){
		perror(message);
	}else{
		printf("ERROR: %s\n", message);
	}
	exit(1);
}

typedef int (*compare_cb) (int a, int b);
typedef int *(*sort_cb) (int *numbers, int count, compare_cb cmp);

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));
    
    if (!target) {
        die("Memory error.");
    }
    
    memcpy(target, numbers, count * sizeof(int));
    
    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            if (cmp(target[j], target[j + 1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }
    
    return target;
}

int *insertion_sort(int *numbers, int count, compare_cb cmp){
	int i = 0;
	int j = 0;
	int temp = 0;
	int *target = malloc(count * sizeof(int));

	if (!target)
		die("Memory error");

	memcpy(target, numbers, count * sizeof(int));

	for (i = 0; i < count; i++){
		j = i;
		while(j > 0 && cmp(target[j-1], target[j]) > 0){
			temp = target[j];
			target[j] = target[j-1];
			target[j-1] = temp;
			j--;
		}
	}
	return target;
}

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	if (a == 0 || b == 0){
		return 0;
	}else{
		return a % b;
	}
}

void test_sorting(int *numbers, int count, sort_cb sort, compare_cb cmp){
	
	int i = 0;
	int *sorted = sort(numbers, count, cmp);

	if(!sorted)
		die("Failed to sort as requested.");

	for(i = 0; i < count; i++){
		printf("%d ", sorted[i]);
	}
	printf("\n");

	free(sorted);


	// printf("\n\n");

}

void data_hex (int *numbers, int count, compare_cb cmp){
	int i = 0;

	unsigned char *data = (unsigned char *)cmp;

	for (i = 0; i < 25; i++){
		printf("%02x:", data[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	if (argc < 2) 
		die("USAGE: ex18 4 3 1 6 5");
	int count = argc -1;
	int i = 0;
	char **inputs = argv + 1;

	int *numbers = malloc(count * sizeof(int));

	if(!numbers)
		die("Memory error");

	for(i = 0; i < count; i++){
		numbers[i] = atoi(inputs[i]);
	}

	puts("Bubble Sort:");
	test_sorting(numbers, count, bubble_sort, sorted_order);
	test_sorting(numbers, count, bubble_sort, reverse_order);
	test_sorting(numbers, count, bubble_sort, strange_order);
	printf("\n");
	puts("Insertion Sort:");
	test_sorting(numbers, count, insertion_sort, sorted_order);
	test_sorting(numbers, count, insertion_sort, reverse_order);
	test_sorting(numbers, count, insertion_sort, strange_order);
	printf("\n");
	puts("Hex Data");
	data_hex(numbers, count, sorted_order);
	printf("\n");

	free(numbers);



	return 0;
}









