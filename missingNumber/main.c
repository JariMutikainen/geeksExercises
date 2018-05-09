// Given an myArray of size n-1 and given that there are numbers from 1 to n 
// with one missing, the missing number is to be found.
// The size of the myArray: 10-1
// The elements: 1 2 3 4 5 6 7 8 10
// The correct answer: 9 is the missing number.
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int myArray[N-1] = {1,2,3,4,5,6,7,8,10};
    int missingNumber = -1;
    int expectedNext;
    for(int i=0;i<N-1;i++) {
        if(i==0) {
            expectedNext = myArray[i] + 1;
        } else {
            if(myArray[i] != expectedNext) {
                missingNumber = expectedNext;
                expectedNext = myArray[i] + 1;
            }
        }
    }
    printf("The missing number in ");
    for(int i=0;i<N-1;i++) {
        printf("%d ",myArray[i]);
    }
    printf("\nis %d\n",missingNumber);
    return 0;
}
