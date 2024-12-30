#include <stdio.h>

#include "stack.h"
#include "testStack.h"

int main(void) {
	if (!testCreateStack() || !testIsEmpty() || !testPop() || !testPush()) {
		printf("���� �� ������ ����\n");
		return 10;
	}
	Stack* stack = createStack();
	push(stack, 1);
}