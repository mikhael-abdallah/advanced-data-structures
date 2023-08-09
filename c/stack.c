#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int top;
    int size;
} Stack;

int top(Stack * stack) {
    if(stack->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->data[stack->top];
}

void push(Stack* stack, int value) {
    if (stack->top == stack->size - 1) {
        stack->size *= 2;
        stack->data = realloc(stack->data, stack->size * sizeof(int));
    }
    stack->data[++(stack->top)] = value;
}

int pop(Stack* stack) {
    if(stack->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    if (stack->top == stack->size / 4) {
        stack->size /= 2;
        stack->data = realloc(stack->data, stack->size * sizeof(int));
    }
    return stack->data[(stack->top)--];
}

void printStack(Stack* stack) {
    printf("[");
    if(stack->top > 0) {
        printf("%d", stack->data[0]);
    }
    for (int i = 1; i <= stack->top; i++) {
        printf(", %d", stack->data[i]);
    }
    printf("]\n");
}

Stack createStack(int initialSize) {
    Stack stack;
    stack.data = malloc(initialSize * sizeof(int));
    stack.top = -1;
    if(initialSize < 1) initialSize = 1;
    stack.size = initialSize;
    return stack;
}

int main() {
    int initialSize = 1;
    Stack stack = createStack(initialSize);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printStack(&stack);
    printf("stack size: %d\n",stack.size);

    printf("pop: %d\n", pop(&stack));
    printf("stack size: %d\n",stack.size);
    printf("pop: %d\n", pop(&stack));
    printf("stack size: %d\n",stack.size);
    printf("pop: %d\n", pop(&stack)); 
    printf("stack size: %d\n",stack.size);

    printf("pop: %d\n", pop(&stack)); 
    printf("stack size: %d\n",stack.size);

    printStack(&stack);


    free(stack.data);

    return 0;
}
