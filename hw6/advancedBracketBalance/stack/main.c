#include <stdio.h>

#include "stack.h"
#include "testStack.h"

int main(void) {
	if (!testCreateStack() || !testIsEmpty() || !testPop() || !testPush()) {
		printf("Стек не прошел тест\n");
		return 10;
	}
	Stack* stack = createStack();
	push(stack, 1);
}