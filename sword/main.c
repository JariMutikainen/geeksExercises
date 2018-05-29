// Read the assignment for this exercise in 'assignment.txt'.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// the final MAXPEOPLE is 10^8 - but let's start with 50
#define MAXPEOPLE 50

int main()
{
    void killNext(bool peopleAlive[], int N, int swordHolder);
    void passOnTheSword(bool peopleAlive[], int N, int* swordHolder);
    bool peopleAlive[MAXPEOPLE + 1] = {false}; // Element 0 will not be used
    FILE* in = fopen("input.txt","r");
    if(!in) {
        printf("Unable to open the input file.\n");
        return 1;
    }
    int T; // The number of the test cases
    int N; // The number of people standing in a ring
    int deadPeople,swordHolder;
    fscanf(in,"%d",&T);
    for(int t=0;t<T;t++) {
        fscanf(in,"%d",&N);
        // All the N people are alive in the begining:
        for(int i=1;i<=N;i++) {
            peopleAlive[i] = true;
        }
        deadPeople = 0;
        swordHolder = 1; // The 1st person gets the sword at the start.
        while(deadPeople < N - 1) {
            killNext(peopleAlive,N,swordHolder);
            passOnTheSword(peopleAlive,N,&swordHolder);
            deadPeople++;
        }
        printf("\n\n-------> The survivor is the person number %d.\n\n",
                swordHolder);
    }


    fclose(in);
    return 0;
}
//------------------------------ killNext ------------------------------  
void killNext(bool peopleAlive[], int N, int swordHolder) {
    // Finds out who the next living person is and kills him/her.
    // Look for the next person to be killed starting at the next person.
    int p = (swordHolder == N) ? 1 : swordHolder + 1; 
    while(peopleAlive[p] == false) p = (p == N) ? 1 : (p + 1); // Skip the dead.
    // At this point p is pointing at the next person alive. Kill him/her.
    peopleAlive[p] = false;
    printf("Person %d killed the person %d.\n",swordHolder,p);
    return;
}
//------------------------------ passOnTheSword ------------------------------  
void passOnTheSword(bool peopleAlive[], int N, int* swordHolder) {
    // Find the next person alive and pass the sword to him/her.
    int p = (*swordHolder == N) ? 1 : *swordHolder + 1; 
    while(peopleAlive[p] == false) p = (p == N) ? 1 : (p + 1); // Skip the dead.
    // At this point p is pointing at the next person alive. 
    // Give the sword to him/her.
    printf("Person %d passed the sword to the person %d.\n",*swordHolder,p);
    *swordHolder = p;
    return;
}
