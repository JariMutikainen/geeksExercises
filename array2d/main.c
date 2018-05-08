// Find the assignment for ths exercise in the file 'assignment.txt'.

#include <stdio.h>
#include <stdlib.h>


int main()
{
    void getDimensions(FILE* infile, int* n, int* m);
    int* makeMatrix(FILE* infile, int r, int c);
    void printMatrix(int* matrix, int r, int c);
    void findMinOnes(int* matrix, int r, int c);
    int* matrix = NULL; // a pointer to the element [0][0] of a 2 dimensional matrix
    int T,rows,cols;

    FILE* infile = fopen("input.txt","r");
    if(NULL == infile) {
        printf("Unable to open infile.txt.\n");
        return -1;
    }
    fscanf(infile,"%d",&T);
    getDimensions(infile,&rows,&cols);
    matrix = makeMatrix(infile,rows,cols);
    printMatrix(matrix,rows,cols);
    findMinOnes(matrix,rows,cols);
    free(matrix);
    matrix = NULL;



    fclose(infile);
    return 0;
}
//------------------------------ getDimensions ------------------------------  
void getDimensions(FILE* infile, int* n, int* m) {
    // Gets the dimensions of the 2D matrix from the input file.
    fscanf(infile,"%d %d", n, m);
    return;
}
//------------------------------ makeMatrix ------------------------------   
int* makeMatrix(FILE* infile, int r, int c) {
    // Reads the values for the elements of the 2D-matrix from the input file.
    // Returns a pointer to the 1st element of the created matrix.
    int* newMatrix = (int*)malloc(r * c * sizeof(int));
    if(newMatrix == NULL) {
        printf("Unable to allocate memory for the 2D matrix.\n");
        return NULL;
    }
    for(int row = 0;row < r; row++) {
        for(int col = 0;col < c;col++) {
            fscanf(infile,"%d",(newMatrix + row * c + col));
        }
    }
    return newMatrix;
}
//------------------------------ printMatrix ------------------------------  
void printMatrix(int* matrix, int r, int c) {
    // Prints the contents of the 2D matrix.
    for(int row=0;row<r;row++) {
        for(int col=0;col<c;col++) {
            printf("%d ",*(matrix + row * c + col));
            if(col == c-1) printf("\n");
        }
    }
    return;
}
//------------------------------ findMinOnes ------------------------------  
void findMinOnes(int* matrix, int r, int c) {
    // Prints the number of the row, which contains the smallest number
    // of ones. All rows contain only zeros and ones, and have been sorted
    // into the ascending order.

    int firstOne = 1000; // Out of range value on purpose
    int winnerRow = -1;
    for(int row=0;row<r;row++) {
        for(int col=0;col<c;col++) {

