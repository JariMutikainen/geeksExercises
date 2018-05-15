// Find the assignment in the file 'assignment.txt'.
// WARNING: THIS PROGRAM FAILS, WHEN THE INPUT IS ()[].
// I have no solution to this shortcoming.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100


int main()
{
    char inString[MAXLEN + 1];
    char openings[50];
    char closings[50];
    int T;
    FILE* infile = fopen("input.txt","r");
    if(!infile) {
        printf("Unable to open infile.\n");
        return -1;
    }
    fscanf(infile,"%d",&T);
    //printf("T = %d\n",T);
    for(int i=0;i<T;i++) {

        fscanf(infile,"%s",inString);
        printf("inString: %d characters: %s\n",strlen(inString),inString);
        char *pi, *po, *pc;
        pi = inString;
        po = openings;
        pc = closings;
        while(*pi != '\0') {
            if(*pi == '(' || *pi == '{' || *pi == '[') {
                *po++ = *pi;
            } else if(*pi == ')' || *pi == '}' || *pi == ']') {
                *pc++ = *pi;
            }
            pi++;
        }
        *po = '\0';
        *pc = '\0';
        printf("Openings: %s: %d, Closings: %s: %d\n",openings,strlen(openings),
                closings, strlen(closings));
        if(strlen(openings) != strlen(closings)) {
            printf("Not balanced\n");
            return 0;
        }
        po = openings;
        pc = closings + strlen(closings) - 1; // Point at the last character
        while(*po != '\0') {
            int error = 0;
            if(*po == '(' && (*pc != ')')) error = 1;
            else if(*po == '{' && (*pc != '}')) error = 1;
            else if(*po == '[' && (*pc != ']')) error = 1;
            if(error) {
                printf("Not balanced\n");
                return 0;
            }
            po++;
            pc--;
        }
        printf("Balanced\n");
    }

    fclose(infile);
    return 0;
}
