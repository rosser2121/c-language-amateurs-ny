#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *name;
	int age;
	int height;
	int weight;
} Person;


struct Person *Person_create(char *name, int age, int height, 
	int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
};

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);	
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);	
}

int main(int argc, char *argv[])
{
	
	struct Person *joe = Person_create("Joe Bloe", 32, 72, 180);

	struct Person *mike = Person_create("Mike Morton", 28, 71, 165);
	Person_print(joe);
	Person_print(mike);

	printf("Joe's over at memory location: %p\n", joe);
	printf("Mike's memory address is: %p\n", mike);

	printf("Mike name struct address: %p\n", &mike->name);
	printf("Mike size: %ld\n", sizeof(mike));
	printf("Mike name size: %ld\n", sizeof(mike->name));

	Person_destroy(joe);
	Person_destroy(mike);

	return 0;
}