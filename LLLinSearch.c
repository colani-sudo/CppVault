#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;    //global pointer

void create(int A[], int n)
{
    int i;
    struct Node *t; //to point to first or head node
    struct Node *last; //to point to tail node
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last=first;

    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
struct Node*  LSearch(struct Node *p, int key){//linear search
    while(p!=NULL){
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}
struct Node* RSearch(struct Node *p, int key){
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next,key);
}
int main(){
    struct Node* temp;
    int A[] = {3,5,10,15,8,12,20};
    create(A,sizeof(A)/sizeof(int));
    temp = LSearch(first,15);
    if(temp)
        printf("Key is found %d\n",temp->data);
    else
        printf("Key not found\n");

    return 0;
}