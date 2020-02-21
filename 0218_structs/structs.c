#include <stdio.h>

struct datarecord {
    int intID;
    int intAge;
    float fSalary;
};

int main() {
    struct datarecord John;
    John.intID=1325345;
    John.intAge=25;
    John.fSalary=100.05;
    printf("John is %d years old\n", John.intAge);

    struct datarecord *alias=0;
    alias = &John;
    (*alias).intAge=26;
    printf("John is %d years old\n", John.intAge);
    alias->intAge=27;
    printf("John is %d years old\n", John.intAge);
}