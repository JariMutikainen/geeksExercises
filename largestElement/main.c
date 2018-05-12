// See the assignment in the file 'assignment.txt'.
//
#include <stdio.h>
#include <stdlib.h>
#define ELEMENTS 100

int main()
{
    void getInputs(FILE* in, int* N, int* k, int* arr);
    void printArr(int* arr, int N);
    void sortArr(int* arr, int N);
    int arr[ELEMENTS] = {0};
    int T,N,k;
    FILE* infile = fopen("input.txt","r");
    if(NULL == infile) {
        printf("Unable to open input file.\n");
        return -1;
    }
    fscanf(infile,"%d",&T);
    for(int i=0;i < T;i++) {
        getInputs(infile,&N,&k,arr);
        printArr(arr,N);
        sortArr(arr,N);
        //printArr(arr,N);
        printArr(arr,k); // Print the first k largest elements.
    }





    fclose(infile);
    return 0;
}
//------------------------------ getInputs ------------------------------  
void getInputs(FILE* in, int* N, int* k, int* arr) {
    // Gets the input values from the input file.
    fscanf(in,"%d %d",N,k);
    for(int i=0;i<*N;i++) {
        fscanf(in,"%d",(arr + i));
    }
    return;
}
//------------------------------ printArr ------------------------------  
void printArr(int* arr, int N) {
    // Prints the elements of the arr[]
    for(int i=0;i<N;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}
//------------------------------ sortArr ------------------------------  
void sortArr(int* arr, int N) {
    // Sorts the elements of arr[] into the descending order.
    void swap(int* a, int* b);
    for(int largest = 0;largest < N-1;largest++) {
        for(int i=largest+1;i<N;i++) {
            if(arr[i] > arr[largest]) {
                swap((arr + i), (arr + largest)); // Swap
            }
        }
    }
    return;
}
//------------------------------ swap ------------------------------  
void swap(int* a, int* b) {
    // Swaps the two elements of the array.
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

