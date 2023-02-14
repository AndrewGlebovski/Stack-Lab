#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Node {
    int data            = 0;
    struct Node *prev   = nullptr;
};


struct Stack {
    int size            = 0;
    Node *head          = nullptr;
};


int stack_push(Stack *stack, int new_element);


int stack_top(Stack *stack, int *top_element);


int stack_pop(Stack *stack);


void node_destructor(Node *node);


int stack_destructor(Stack *stack);


int stack_dump(Stack *stack);


#include "test.hpp"


int main() {
    Stack stack = {};

    printf("Test 1. CPU time used: %g ms\n", test1(&stack));

    stack_destructor(&stack);

    printf("Test 2. CPU time used: %g ms\n", test2(&stack));

    stack_destructor(&stack);

    printf("Test 3. CPU time used: %g ms\n", test3(&stack));
    
    stack_destructor(&stack);

    return 0;
}


int stack_push(Stack *stack, int new_element) {
    if (stack == nullptr) return 0;
    
    Node *top = (Node *) calloc(1, sizeof(Node));
    
    if (top == nullptr) return 0;
    
    top -> data = new_element;
    top -> prev = stack -> head;
    
    stack -> size++;
    stack -> head = top;
    
    return 1;
}


int stack_top(Stack *stack, int *top_element) {
    if (stack == nullptr) return 0;
    if (stack -> head == nullptr) return 0;
    
    *top_element = stack -> head -> data;
    
    return 1;
}


int stack_pop(Stack *stack) {
    if (stack == nullptr) return 0;
    if (stack -> head == nullptr) return 0;
    
    Node *ptr = stack -> head;
    
    stack -> size--;
    stack -> head = stack -> head -> prev;
    
    free(ptr);
    
    return 1;
}


void node_destructor(Node *node) {
    if (node == nullptr) return;
    
    node_destructor(node -> prev);
    
    free(node);
}


int stack_destructor(Stack *stack) {
    if (stack == nullptr) return 0;
    
    node_destructor(stack -> head);

    stack -> head = nullptr;
    stack -> size = 0;

    return 1;
}


int stack_dump(Stack *stack) {
    if (stack == nullptr) return 0;
    
    printf("STACK\n");
    
    printf("size: %i\n", stack -> size);
    
    for (Node *iter = stack -> head; iter != nullptr; iter = iter -> prev)
        printf("  [%p] %i\n", iter, iter -> data);
    
    return 1;
}
