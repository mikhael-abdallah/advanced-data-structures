#include <stdio.h>
#include <stdlib.h>

typedef struct PersistentStack PersistentStack;

struct PersistentStack {
    int value;
    int size;
    PersistentStack* parent;
};

PersistentStack createPersistentStack(int value, PersistentStack* parent, int size) {
    PersistentStack stack;
    stack.value = value;
    stack.size = size;
    stack.parent = parent;
    return stack;
}

PersistentStack push(PersistentStack* stack, int value) {
    return createPersistentStack(value, stack, stack->size + 1);
}

PersistentStack pop(PersistentStack* stack) {
    if(stack->parent == 0) {
        printf("stack is empty!\n");
        return *stack;
    }
    return *(stack->parent);
}

int top(PersistentStack * stack) {
    if(stack->parent == 0) {
        printf("stack is empty!\n");
        return 0;
    }
    return stack->value;
}


void printHelper(PersistentStack* stack, int index) {
        if (stack->parent == 0) {
            return;
        }

        if(index > 0) {
            printf(",");
        };
        printf("%d", stack->value);

        printHelper(stack->parent, index + 1);
}


void printStack(PersistentStack* stack, int i) {
    printf("stack%d top: %d, stack: ", i, top(stack));
    printf("[");
    printHelper(stack, 0);
    printf("]\n");
}


int main() {
    int initialSize = 1;
    PersistentStack stack1 = createPersistentStack(0, 0, initialSize);

    PersistentStack stack2 = push(&stack1, 1);
    PersistentStack stack3 = push(&stack2, 2);

    PersistentStack stack4 = pop(&stack3);
    PersistentStack stack5 = pop(&stack4);


    printStack(&stack1, 1);
    printStack(&stack2, 2);
    printStack(&stack3, 3);
    printStack(&stack4, 4);
    printStack(&stack5, 5);

    return 0;
}
