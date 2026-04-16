#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char* s) {
    top = -1;

    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty())
                return 0;

            char topChar = pop();
            if (!isMatching(topChar, ch))
                return 0;
        }
    }

    return isEmpty();
}

int main() {
    char s[MAX];

    printf("Enter a string: ");
    scanf("%s", s);

    if (isBalanced(s))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
