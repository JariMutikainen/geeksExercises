// Find the assignment for this exercise on 'assignment.txt'.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* infile = fopen("input.txt","r");
    if(NULL == infile) {
        printf("Unable to open input.txt.\n");
        return -1;
    }

    fclose(infile);
    return 0;
}
