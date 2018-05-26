/* Given a singly linked list, find middle of the linked list. For example, 
 * if given linked list is 1->2->3->4->5 then output should be 3. 

* If there are even nodes, then there would be two middle nodes, we need to 
* print second middle element. For example, if given linked list is 1->2->3->4->
* 5->6 then output should be 4.
* 
* Input:
* You have to complete the method which takes one argument: the head of the 
* linked list. You should not read any input from stdin/console.
* The struct Node has a data part which stores the data and a next pointer 
* which points to the next element of the linked list. 
* There are multiple test cases. For each test case, this method will be called 
* individually.
* 
* Output:
* Your function should return data of linked list.  If linked list is empty, 
* then return -1.
* 
* Constraints:
* 1 <=T<= 30
* 1 <=N<= 100
* 1 <=value<= 1000
* 
* Example:
* Input:
* 2
* 5
* 1 2 3 4 5
* 6
* 2 4 6 7 5 1
* 
* Output:
* 3
* 7
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int val;
    struct node_s* next;
} node_t;

int main()
{
    int T,N;
    node_t* head = NULL;
    FILE* infile = fopen("input.txt","r");
    if(!infile) {
        printf("Unable to open input file. Investigate.\n");
        return -1;
    }
    fscanf(infile,"%d",&T);
    void getInputs(FILE* in, node_t** top, int* N);
    void printList(node_t* top); 
    void pickMiddleNode(node_t* top);
    void releaseNodes(node_t** top);
    for(int i=0;i<T;i++) {

        getInputs(infile,&head,&N);
        printList(head);
        pickMiddleNode(head);
        releaseNodes(&head);
    }
    


    fclose(infile);
    return 0;
}
//------------------------------ getInputs ------------------------------  
void getInputs(FILE* in, node_t** top, int* N) {
    // Get the inputs from the input file and build the linked list into
    // the heap.
    node_t* newNode = NULL;
    node_t* tail = NULL;
    fscanf(in,"%d",N);
    for(int i=0;i<*N;i++) {
        newNode = (node_t*)malloc(sizeof(node_t));
        fscanf(in,"%d",&(newNode->val));
        newNode->next = NULL;
        // Add the new node into the tail of the linked list
        if(tail == NULL) { // This will be the 1st node of the list.
            *top = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return;
}
//------------------------------ printList ------------------------------  
void printList(node_t* top) { 
    // Prints the elements of the linked list.
    node_t* p = top;
    if(!p) {
        printf("The list is empty.\n");
        return;
    }
    while(p->next != NULL) {
        printf("%d ",p->val);
        p = p->next;
    }
    // p is pointing at the last node now.
    printf("%d\n",p->val);
    return;
}
//------------------------------ pickMiddleNode ------------------------------  
void pickMiddleNode(node_t* top) {
    // Picks and prints out the middle node of the linked list.
    node_t* p = top;
    if(!p) {printf("-1\n"); return;} // An empty list
    int nodes = 0;
    // Count the number of the nodes in the list
    while(p->next != NULL) {
        nodes++;
        p = p->next;
    }
    nodes++;

    int midNodeIndex = nodes / 2; // Integer division returns an integer.
    p = top; // Start over from the begining of the list
    for(int i=0;i<midNodeIndex;i++) {
        p = p->next;
    }
    printf("%d\n",p->val);
    return;
}
//------------------------------ releaseNodes ------------------------------  
void releaseNodes(node_t** top) {
    // Release the nodes from the heap
    node_t* p = *top;
    if(!p) {printf("-1\n"); return;} // An empty list
    node_t* tmp = NULL;
    while(p->next != NULL) {
        tmp = p->next;
        //printf("Releasing %d\n",p->val);
        free(p);
        p = tmp;
    }
    // p is pointing at the last node now
    //printf("Releasing %d\n",p->val);
    free(p);
    *top = NULL;
    return;
}

