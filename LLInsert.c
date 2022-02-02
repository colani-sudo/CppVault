#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
}*first = NULL;
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
//inserting new node
 void insertFront(struct Node *p, int index, int x){
     struct Node *t, *p; 
     if(index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    
     if(index==0)   //insert new Node in front  //time - O(1)
     {
        t->next = first;
        first = t;
     }
     else{
    //insert new Node after given position, eg pos=4 
    //min - O(1)  max - O(n)
     int i;
     for(i=0; i<index-1 && p; i++){
         p=p->next;
     }
     if(p)
     {
        t->next = p->next;
        p->next = t;
     }
    }
 }

int main(){
    int A[] = {3,5,10,15,8,12,20};

    create(A,sizeof(A)/sizeof(int));


    return 0;
}