#include <stdio.h>

int main() {
    int i;
    for(i=0; i<10; i++){
        printf("%d ", i);
    }
    printf("\n");

    int line, star;
    for(line=1; line<=10; line++){
        //  printf("%d ", line); 
        for(star=1; star<=line; star++) {
            printf("*");
        }
        printf("\n");
    }

}