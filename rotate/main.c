// The original assignment can be found in the neighboring file 
// 'assignment.txt'. In this exercise we skip the part of reading the input data
// from the input file, because it has been done many times in earlier 
// exercises. We concentrate on implementing the rotate algorithm instead.

#include <stdio.h>
#include <stdlib.h>
#define N 8

int main()
{
    int a[N] = {1,2,3,4,5,6,7,8};
    int b[N];
    int d = 3;

    for(int i= 0;i<N;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");

    for(int i=0;i<d;i++) {
        b[i] = a[i]; // Copy left the side head of the original array.
    }
    for(int i=0;i<N-d;i++) {
        a[i] = a[d+i]; // Shift left d positions
    }
    for(int i=0;i<d;i++) {
        a[N-d+i] = b[i]; // Append the original head to a[].
    }

    for(int i= 0;i<N;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");


    return 0;
}
