#include <stdio.h>

int product(int, int);
void parameters(int,int*);
int main() {
    int a, b;
    printf("Please enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("You entered %d and %d\n", a, b);
    int tmp=product(a, b);
    printf("%d * %d = %d\n", a,b,tmp);
    printf("a=%d, b=%d\n",a,b);
    parameters(a,&b);
    printf("a=%d, b=%d\n",a,b);
}
void parameters(int first, int *second) {
    first = 10;
    *second = 20;
    printf("First: %d, second: %d\n", first, *second);
}

int product(int x, int y){
    int result = x * y;
    return result;
}

