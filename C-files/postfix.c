#include <stdio.h>
#include <stdbool.h>

#define max 50

int stack[max];
int top = -1;

void push(int val) {
    if (top == max - 1) {
        printf("Stack is full\n");
        return;
    }

    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack[top--];
}

int main() {

    char str[max];

    scanf(" %[^\n]", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            continue;
        if (str[i] >= '0' && str[i] <= '9') {

            int number = 0;

            while (str[i] >= '0' && str[i] <= '9') {
                number = number * 10 + (str[i] - '0');
                i++;
            }

            i--;

            push(number);
        }
        else {

            int op2 = pop();
            int op1 = pop();

            int result;

            switch (str[i]) {

                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    if (op2 == 0) {
                        printf("Not divisible by 0\n");
                        return 0;
                    }

                    result = op1 / op2;
                    break;

                default:
                    printf("Invalid operator\n");
                    return 0;
            }

            push(result);
        }
    }

    printf("%d\n", pop());

    return 0;
}
