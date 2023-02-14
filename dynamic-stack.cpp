#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef int stack_data_t;


typedef struct {
    stack_data_t *data;
    int capacity;
    int size;
} Stack;


#define MAX_CAPACITY_VALUE 100000


int stack_constructor(Stack *stack, int capacity);


int stack_push(Stack *stack, stack_data_t object);


int stack_pop(Stack *stack);


int stack_destructor(Stack *stack);


int stack_resize(Stack *stack);


int stack_clear(Stack *stack);


int stack_top(Stack *stack, stack_data_t *top_element);


#include "test.hpp"


int main() {
    Stack stack = {NULL, 0, 0};

    stack_constructor(&stack, 1);

    printf("Test 1. CPU time used: %g ms\n", test1(&stack));

    stack_clear(&stack);

    printf("Test 2. CPU time used: %g ms\n", test2(&stack));

    stack_clear(&stack);

    printf("Test 3. CPU time used: %g ms\n", test3(&stack));
    
    stack_destructor(&stack);
}


int stack_constructor(Stack *stack, int capacity) {
    stack -> data = (stack_data_t *) calloc(capacity, sizeof(stack_data_t));
    
    stack -> capacity = capacity;
    stack -> size = 0;

    return 0;
}


int stack_resize(Stack *stack) {
    if (4 * stack -> size < stack -> capacity)
        stack -> capacity /= 2;
    
    else if (stack -> size == stack -> capacity)
        stack -> capacity *= 2;

    else 
        return 0;

    stack -> data = (stack_data_t *) realloc(stack -> data, stack -> capacity * sizeof(stack_data_t));

    return 0;
}


int stack_clear(Stack *stack) {
    stack_destructor(stack);
    stack_constructor(stack, 1);

    return 0;
}


int stack_top(Stack *stack, stack_data_t *top_element) {
    *top_element = (stack -> data)[stack -> size - 1];

    return 0;
}


int stack_push(Stack *stack, stack_data_t new_data) {
    (stack -> data)[(stack -> size)++] = new_data;

    return stack_resize(stack);
}


int stack_pop(Stack *stack) {
    stack -> size--;

    return stack_resize(stack);
}


int stack_destructor(Stack *stack) {
    free((char *)(stack -> data));

    stack -> data = NULL;
    
    stack -> capacity = 0;
    stack -> size = 0;

    return 0;
}
