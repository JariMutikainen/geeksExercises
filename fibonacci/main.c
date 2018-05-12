// Given a positive integer N, find the Nth fibonacci number. Since the answer 
// can be very large, print the answer modulo 1000000007.
// 1<=N<=1000
// 
// Example:
// 
// Input:
// 3
// 1
// 2
// 5
// 
// Output:
// 1
// 1
// 5

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prev = 0;
    int curr = 1;
    int i = 1;
    int N = 5;
    int temp;

    while(i <= N) {
        if(i == N) printf("Fibonacci[%d] = %d\n",i,curr % 1000000007);
        temp = curr;
        curr += prev;
        prev = temp;
        i++;
    }

    return 0;
}
