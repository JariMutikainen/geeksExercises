// Given a positive integer N, check if N is a power of 2.
// 0<=N<=10^18

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberOfOnes;
    int n,answ=2;
    int bit;
    while(answ > 0) {
        printf("Enter an integer: ");
        scanf("%d",&answ);
        
        // The integer is a power of 2 on the condition, that the binary represen-
        // tation of it contains exectly one '1'.
        numberOfOnes = 0;
        bit = 0;
        n = answ;
        for(int i=0;i<31;i++) { // Can process up to 32 bit integers.
            bit = n & 0x00000001; // Pick the LSB bit of n.
            if(bit) numberOfOnes++;
            n = n>>1; // shift left
        }
        if(numberOfOnes == 1) {
            printf("%d is a power of two.\n",answ);
        } else { 
            printf("%d is not a power of two.\n",answ);
        }
    }

    
    
    return 0;
}
