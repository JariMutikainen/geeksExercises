// Find the assignment for this exercise in 'assignment.txt'.

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int indx;
    int val;
    struct node_s* next;
} node_t;

int main()
{
    void getInputs(FILE* infile, int* n, int* k, node_t** head);
    void showList(node_t* head);
    void findNode(node_t* head, int noi);
    void releaseNodes(node_t** head);
    FILE* infile = fopen("input.txt","r");
    if(NULL == infile) {
        printf("Unable to open input.txt.\n");
        return -1;
    }
    int T,n,k;
    int noi; // Node Of Interest
    fscanf(infile,"%d",&T);
    node_t* top = NULL;     // The pointer to the 1st node of the linked list.
    for(int t=0;t<T;t++) {
        getInputs(infile,&n,&k,&top);
        showList(top);
        if(n % k == 0) noi = n / k;
        else noi = n / k + 1; // The poor man's ceil function is here.
        findNode(top,noi);
        releaseNodes(&top);
    }


    fclose(infile);
    return 0;
}
//------------------------------ getInputs ------------------------------  
void getInputs(FILE* infile, int* n, int* k, node_t** head) {
    // Gets the input values from the input file. Builds a linked list
    // of the provided numbers.

    node_t *newNode, *p;

    fscanf(infile,"%d",n);
    for(int i = 1;i <= *n; i++) { // Start i from 1 - not 0.
        // Create a new node.
        newNode = (node_t*) malloc(sizeof(node_t));
        if(NULL == newNode) printf("Malloc() failed. Investigate.\n");
        newNode->indx = i;
        fscanf(infile,"%d",&(newNode->val));
        newNode->next = NULL;
        // Append the new node to the tail of the linked list.
        if(*head == NULL) { // No prior nodes in the list
            *head = newNode; // The new node becomes the 1st and the only node.
        } else { // Prior nodes exist.
            p = *head; // Make p point at the 1st node.
            while(p->next != NULL) {
                p = p->next; // Move on until you point at the last node.
            }
            // p is pointing at the last node at this point.
            p->next = newNode; // Append the new node to make it the new last.
        }
    }
    fscanf(infile,"%d",k);

    return;
}
//------------------------------ showList ------------------------------  
void showList(node_t* head) {
    // Prints the contents of the linked list
    node_t* p = head;
    printf("\n");
    if(NULL == p) {
        printf("The linked list is empty.\n");
    } else {
        while(p->next != NULL) {
            printf("Node %d, value %d\n",p->indx,p->val);
            p = p->next;
        }
        // p is pointing at the last node of the list now.
        printf("Node %d, value %d\n",p->indx,p->val);
    }
    return;
}
//------------------------------ findNode ------------------------------  
void findNode(node_t* head, int noi) {
    // Finds and prints out the node of interest.
    node_t* p = head;
    if(NULL == p) {
        printf("The list is empty. No element to print.\n");
        return;
    }
    while(p->next != NULL) {
        if(p->indx == noi) {
            printf("\nNode of interest: %d, val = %d.\n",p->indx,p->val);
            return;
        }
        p = p->next;
    }
    // p is pointing at the last node now.
    if(p->indx == noi) {
        printf("\nNode of interest: %d, val = %d.\n",p->indx,p->val);
    }
    return;
}
//------------------------------ releaseNodes ------------------------------  
void releaseNodes(node_t** head) {
    // Releases all the nodes of the linked list and sets the top
    // pointer in main to NULL.
    node_t *p = *head, *temp = NULL;
    while(p->next != NULL) {
        //printf("Releasing Node %d, val = %d.\n",p->indx,p->val);
        temp = p->next;
        free(p);
        p = temp;
    }
    // p is pointing at the last node now
    //printf("Releasing Node %d, val = %d.\n",p->indx,p->val);
    free(p);
    *head = NULL;
    return;
}
