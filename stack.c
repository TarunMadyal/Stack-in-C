#include <stdio.h>
#include <stdlib.h>
#define max 4

int top = -1;
int stack_arr[max];

int isFull() {
    return (top == max - 1) ? 1 : 0;
}

int isEmpty() {
    return (top == -1) ? 1 : 0;
}

void push(int data) {
    if (isFull()) {
        printf("Stack Overflow.\n");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        return -1; // Return a sentinel value or handle underflow accordingly
    }
    int value = stack_arr[top];
    top = top - 1;
    return value;
}

int peek() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        return -1; // Return a sentinel value or handle underflow accordingly
    }
    return stack_arr[top];
}

void print() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Push\n2. Pop\n3. Display top element of Stack\n4. Display all the elements of stack\n5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to be pushed:\n");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1)
                    printf("Deleted element is %d\n", data);
                break;
            case 3:
                printf("Top element is: %d\n", peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
