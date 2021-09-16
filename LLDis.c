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
/*
void Display(struct Node *p){   //display linkedlist using a loop
    while(p != NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    //printf("\n");
}*/

void Display(struct Node *p){   //display linkedlist using recursion
        if(p!=NULL){
            printf("%d ",p->data);
            Display(p->next);
        }

}
int counter(struct Node *p){    //counting nodes using a loop
    int c=0;
    while(p!=0){
        c++;
        p=p->next;
    }
    return c;
}
int Rcounter(struct Node *p){    //counting nodes using recursion 
    
    if(p==0)
        return 0;
    else
        return Rcounter(p->next)+1;
}
int Add(struct Node *p){    //summing elements using a loop
    int sum = 0;
    while(p){
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}
int RAdd(struct Node *p){    //summing elements using recursion
    if(p==0)
        return 0;
    else
        return RAdd(p->next)+p->data;
}
int main()
{
    int A[] = {3,5,10,15,8,12,20};

    create(A,sizeof(A)/sizeof(int));

    Display(first);
    printf("\n");
    printf("%d \n",counter(first));
    printf("%d \n", Add(first));

    return 0;
}