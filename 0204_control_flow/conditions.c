#include <stdio.h>

int main() {
    int age;
    printf("How old are you? ");
    scanf("%d", &age);
    if(age>0) {
        if(age<21)
            printf("You cannot legally enjoy alcoholic beverages\n");
        else 
            printf("Hello! Your age is %d\n", age);
    }
    else {
        printf("You entered an invalid age\n");
    }
}