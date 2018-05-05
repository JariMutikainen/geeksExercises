// Find the assignment for this exercise in the neighboring file 
// 'assignment.txt'.

#include <stdio.h>
#include <stdlib.h>
#define ARRSIZE 200
int main()
{
    void buildTestCase(FILE* in, int* a, int* elems, int* product);
    void solveTestCase(int* a, int elems, int product);
    int T,N,a[ARRSIZE],pro;
    FILE* infile = fopen("input.txt","r");
    if(NULL == infile) return -1;
    fscanf(infile,"%d",&T);
    printf("T = %d\n",T);
    
    for(int i=0;i<T;i++) {
        buildTestCase(infile,a,&N,&pro);
        solveTestCase(a,N,pro); 
    }

    fclose(infile);
    return 0;
}
//------------------------------ buildTestCase ------------------------------  
void buildTestCase(FILE* in, int* a, int* elems, int* product) {
    // Gets the input for one test case from the input file.
    
    fscanf(in,"%d %d",elems,product);
    for(int i = 0;i < *elems;i++) {
        fscanf(in, "%d", a+i);
    }
    return;
}
//------------------------------ solveTestCase ------------------------------  
void solveTestCase(int* a, int elems, int product) {
    // Prints 'yes' if a[] contains two elements the product of which is
    // equal to product else print 'no'.

    int num1 = 0,num2 = 0;
    for(int i=0;i<elems-1;i++) {
        if((product % a[i] == 0) && (product != a[i])) {
            num1 = a[i];
            for(int j=i+1;j<elems;j++) {
                if(num1 * a[j] == product) {
                    num2 = a[j];
                    printf("Yes, %d x %d = %d.\n",num1,num2,product);
                    return;
                }
            }
        }
    }
    printf("No.\n");
    return;
}


