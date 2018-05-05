// Read the assignment in the neighboring file: 'assignment.txt'.

#include <stdio.h>
#include <stdlib.h>

typedef struct point_s {
    int x;
    int y;
} point_t;

typedef struct rect_s {
    point_t northWest;
    point_t southEast;
} rect_t;

int main()
{
    void getInputs(FILE* in,rect_t* a, rect_t* b);
    void solveTestCase(rect_t* a, rect_t* b);
    FILE* infile = fopen("input.txt","r");
    if(NULL == infile) {
        printf("Can't open input file.\n");
        return -1;
    }

    rect_t rectA,rectB;
    int T;
    fscanf(infile,"%d",&T);
    printf("%d test cases.\n",T);
    for(int i=0;i<T;i++) {
        getInputs(infile,&rectA,&rectB);
        solveTestCase(&rectA,&rectB);
    }
    fclose(infile);
    return 0;
}
//------------------------------ getInputs ------------------------------  
void getInputs(FILE* in,rect_t* a, rect_t* b) {
    // Reads the data for the rectangles a and b from the input file.

    fscanf(in,"%d %d %d %d",&(a->northWest.x),&(a->northWest.y),
                            &(a->southEast.x),&(a->southEast.y));
    fscanf(in,"%d %d %d %d",&(b->northWest.x),&(b->northWest.y),
                            &(b->southEast.x),&(b->southEast.y));
    return;
}
//------------------------------ solveTestCase ------------------------------  
void solveTestCase(rect_t* a, rect_t* b) {
    // Print 1 if the two rectangles overlap else print 0.
    
    int bIsAboveA(rect_t* a, rect_t* b);
    int bIsBelowA(rect_t* a, rect_t* b);
    int bIsRightOfA(rect_t* a, rect_t* b);
    int bIsLeftOfA(rect_t* a, rect_t* b);
    if(bIsAboveA(a,b) || bIsBelowA(a,b) || bIsRightOfA(a,b) || bIsLeftOfA(a,b))
        printf("0\n"); // No overlapping
    else
        printf("1\n"); // The two rectangles are overlapping.
    return;
}
//------------------------------ bIsAboveA ------------------------------  
int bIsAboveA(rect_t* a, rect_t* b) {
    // Returns 1 if the rectangle b is above the rectangle a else returns 0.
    return (b->southEast.y > a->northWest.y);
}
//------------------------------ bIsBelowA ------------------------------  
int bIsBelowA(rect_t* a, rect_t* b) {
    // Returns 1 if the rectangle b is below the rectangle a else returns 0.
    return (b->northWest.y < a->southEast.y);
}
//------------------------------ bIsRightOfA ------------------------------  
int bIsRightOfA(rect_t* a, rect_t* b) {
    // Returns 1 if the rectangle b is right of the rectangle a else returns 0.
    return (b->northWest.x > a->southEast.x);
}
//------------------------------ bIsLeftOfA ------------------------------  
int bIsLeftOfA(rect_t* a, rect_t* b) {
    // Returns 1 if the rectangle b is left of the rectangle a else returns 0.
    return (b->southEast.x < a->northWest.x);
}
