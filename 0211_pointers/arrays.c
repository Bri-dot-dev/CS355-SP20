#include <stdio.h>

int intArray[100];

int main(){
    for(int i=0; i<100; i++) {
        intArray[i] = i * 2;
    }

    for(int i=0; i<100; i++) {
        printf("intArray[%d] = %d\n", i, intArray[i]);
    }

    //int x = *(intArray + 15);
    int x = intArray[15];
    printf("x=%d\n",x);
}