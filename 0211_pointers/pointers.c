#include <stdio.h>

int x=5;
int* p=&x;

int main() {
    printf("My pointer: %d\n", *p);
    *p = 10;
    printf("My pointer: %d\n", *p);

    int y = 3 + 5 * (*p);
    int* anotherPointer=0;

    anotherPointer=&y;
    printf("My other pointer: %d\n", *anotherPointer);
}