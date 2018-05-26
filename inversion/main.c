// Given a non-negative integer n. The problem is to invert the bits of n and 
// print the number obtained after inverting the bits. Note that the actual 
// binary representation of the number is being considered for inverting the 
// bits, no leading 0’s are being considered.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXBITS 8

int main()
{
    int binaryNum[MAXBITS] = {0};
    int invertedBinaryNum[MAXBITS] = {0};
    printf("Enter an integer 0 - 255: ");
    int num;
    scanf("%d",&num);
    int temp = num;
    int msbIndex = 0;
    for(int i=0;i<MAXBITS;i++) {
        binaryNum[i] = temp & 0x1; // Pickk the LSB.
        if(binaryNum[i] == 1) msbIndex = i;
        temp >>= 1; // Shift right by one bit position.
    }
    // Invert the bits of the binaryNum
    for(int i=0;i<=msbIndex;i++) {
        invertedBinaryNum[i] = (binaryNum[i]) ? 0 : 1;
    }
    // Turn the bits of the invertedBinaryNum into a newInt.
    int newInt = 0;
    for(int i=0;i<=msbIndex;i++) {
        if(invertedBinaryNum[i]) {
            newInt += (int)pow(2.0,(double)i); // Add 2^i
        }
    }
    // Print out the results of the binary inversion of num.
    printf("%3d = ",num);
    for(int i=msbIndex;i>=0;i--) {
        printf("%1d",binaryNum[i]);
    }
    printf(" becomes \n%3d = ",newInt);
    for(int i=msbIndex;i>=0;i--) {
        printf("%1d",invertedBinaryNum[i]);
    }
    printf("\nWhen inverted bit by bit.\n");
    return 0;
}
