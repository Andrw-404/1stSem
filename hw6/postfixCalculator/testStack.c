#include "stack.h"
#include "testStack.h"

#include <stdbool.h>
#include <stdlib.h>

bool testCreateStack() {
    Stack* stack = createStack();
    return (stack != NULL && isEmpty(stack));
}

bool testPush() {
    Stack* stack = createStack();
    push(stack, 10);
    if (isEmpty(stack) || stack->head->value != 10) {
        return false;
    }

    push(stack, 20);
    return !(isEmpty(stack) || stack->head->value != 20 || stack->head->next->value != 10);
}

bool testPop() {
    Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    pop(stack);

    if (isEmpty(stack) || stack->head->value != 10) {
        return false;
    }

    pop(stack);
    return isEmpty(stack);
}

bool testIsEmpty() {
    Stack* stack = createStack();
    if (!isEmpty(stack)) {
        return false;
    }

    push(stack, 10);
    if (isEmpty(stack)) {
        return false;
    }

    pop(stack);
    return isEmpty(stack);
}