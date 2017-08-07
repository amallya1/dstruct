#include<stdio.h>
int fact(int j);

int main() {
    int i;

    i= fact(5);
    printf("Sum = %d\n", i);
}

int fact(int j) {
    printf("Calculating %d\n", j);

    if(j<=0) {
       return 1;
    } else {
        return (j * fact(j-1));
        printf("Done calculating %d\n", j);    
    }
}
