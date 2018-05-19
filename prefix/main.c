// Find the assignment for this exercise on 'assignment.txt'.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTRINGS 30
#define MAXLEN 50
#define MAXPREFIXES 10

int main()
{
    void getInputs(FILE* infile, char** str, char** pref, int* N, int* Q);
    void findSolutions(char** str, int N, char** pref, int Q); 
    void freeResources(char** str, int N, char** pref, int Q); 
    FILE* infile = fopen("input.txt","r");
    if(NULL == infile) {
        printf("Unable to open input.txt.\n");
        return -1;
    }

    int T,N,Q;
    char* strings[MAXSTRINGS];
    char* prefixes[MAXPREFIXES];

    fscanf(infile,"%d",&T);
    getInputs(infile,strings,prefixes,&N,&Q);
    findSolutions(strings,N,prefixes,Q);
    freeResources(strings,N,prefixes,Q);

    fclose(infile);
    return 0;
}
//------------------------------ getInputs ------------------------------  
void getInputs(FILE* infile, char** str, char** pref, int* N, int* Q) {
    // Read inputs from the input file. Store the strings and prefixes
    // into the heap.

    char strFromFile[MAXLEN+1];
    char* newString = NULL;

    fscanf(infile,"%d",N);
    for(int i=0;i<*N;i++) {
        fscanf(infile, "%s",strFromFile);
        newString = (char*)malloc(strlen(strFromFile) + 1);
        strcpy(newString,strFromFile);
        *(str + i) = newString;
    }
    fscanf(infile,"%d",Q);
    for(int i=0;i<*Q;i++) {
        fscanf(infile, "%s",strFromFile);
        newString = (char*)malloc(strlen(strFromFile) + 1);
        strcpy(newString,strFromFile);
        *(pref + i) = newString;
    }

    return;
}

//------------------------------ findSolutions ------------------------------  
void findSolutions(char** str, int N, char** pref, int Q) {
    // Goes through the list of prefixes one by one and finds out in how
    // many of the strings the prefix in question can be found.

    char *currString = NULL, *currPrefix = NULL;
    char *s = NULL, *p = NULL;
    int hits = 0;
    int missmatch = 0;
    for(int i=0;i<Q;i++) {
        currPrefix = *(pref+i); // Selects one of the prefixes
        hits = 0;
        for(int j=0;j<N;j++) {
            currString = *(str + j); // Selects one of the strings
            p = currPrefix; // Points at the 1st char of currPrefix
            s = currString; // Points at the 1st char of currString
            missmatch = 0;
            while(*p != '\0' && !missmatch) {
                if(*p == *s) {
                    p++;
                    s++;
                } else {
                    missmatch = 1;
                }
            }
            // Either prefix has been exhausted or a missmatch has been found
            if(!missmatch) hits++;
        }
        //printf("prefix %s was found %d times.\n",currPrefix,hits);
        printf("%d\n",hits);
    }


    return;
}
//------------------------------ freeResources ------------------------------  
void freeResources(char** str, int N, char** pref, int Q) {
    // Free the resources in te heap
    for(int i=0;i<Q;i++) {
        free(*(pref+i));
        *(pref+i) = NULL;
    }
    for(int j=0;j<N;j++) {
        free(*(str+j));
        *(str+j) = NULL;
    }
    return;
}

