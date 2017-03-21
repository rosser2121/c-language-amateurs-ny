#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//stack version

struct person {
    char *name;
    int age;
    int height;
    int weight;
};

struct person person_create(char *name, int age, int height, int weight)
{
    struct person p;   
    p.name = strdup(name); 
    p.age = age; 
    p.height = height;
    p.weight = weight;
    return p;
}



int main(void)
{
    struct person joe = {"Joe Bloe", 24, 75, 140};

    printf("%s is located at memory address %p \n", joe.name, &joe);
    return 0;
}