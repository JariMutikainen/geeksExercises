// Find the assignment for this exercise in 'assignment.txt'.

#include <stdio.h>
#include <stdlib.h>
#define SIZE (100 + 1)

int main()
{
    void getInputs(FILE* in, int* arr, int* N, int* target);
    void findSum(int arr[], int N,int sum);
    int arr[SIZE] = {0};
    int T,N,targetSum;
    FILE* infile = fopen("input.txt","r");
    if(NULL == infile) {
        printf("Unable to open input file. Investigate.\n");
        return -1;
    }
    fscanf(infile,"%d",&T);
    for(int i = 0; i < T; i++) {
        getInputs(infile,arr,&N,&targetSum);
        findSum(arr,N,targetSum);
    }

    fclose(infile);
    return 0;
}
//------------------------------ getInputs ------------------------------  
void getInputs(FILE* in, int* arr, int* N, int* target) {
    // Gets the inputs from the input file
    fscanf(in,"%d %d",N,target);
    for(int i=1;i <= *N;i++) { // Skip arr[0] on purpose
        fscanf(in,"%d",(arr+i));
    }
    return;
}
//------------------------------ findSum ------------------------------  
void findSum(int arr[], int N, int sum) {
    // Finds the range of elements in arr[], which add up to sum. Prints
    // the indicies of the 1st and the last element of that range.
    // If no solution is found -1 is printed instead.

    int start,end,curr,cumulatedSum;
    for(int i = 1;i<=N;i++) {
        start = i;
        curr = i;
        cumulatedSum = 0;
        while(curr <= N && cumulatedSum < sum) {
            cumulatedSum += arr[curr];
            curr++;
        }
        if(curr > N) continue; // skip and goto i++ part of the for-loop.
        if(cumulatedSum == sum) {
            end = curr - 1;
            printf("%d %d\n",start,end);
            return;
        } else { // cumulatedSum is > sum
            continue; // goto i++ part of the for loop.
        }
    }
    printf("-1\n");
    return;
}
