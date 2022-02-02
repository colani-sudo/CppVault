#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

class Node
{
public:
	int data;
	Node *next = NULL;
};

class Stack
{
public:
    Stack(){}

    int push(int d)
    {   counter++;
        if(counter == 1){
            head = new Node();
            head->data = d;
            head->next = NULL;
            return 1;
        }else if(counter > 0){
            data = new Node();
            data->data = d;     //question, why did they use data as a variable of an instance and as a data member
            data->next = head;
            head = data;
            return 1;
        }
        counter--;
        return -1;
    }

    int *pop()
    {
        int *remove = new int();
        Node *temp = head;
        
        /*if(counter==1){
            delete[]head;
            counter--;
            return &(remove->data);
        }*/
        if(head!=NULL){
            *remove = head->data;   //derefrencing
            head = head->next;
            counter--;
            delete[]temp;
            return remove;
        }
        return NULL;
    }
private:
    Node *head;
    Node *data;
    int counter = 0;
};

int main()
{
    int data, *temp;
    string command;
    Stack *stack = new Stack();
    while(1)
    {
        cin>>command;
        if(command.compare("exit") == 0)
        {
            break;
        }
        else if(command.compare("push") == 0)
        {
            cout<<"Please input a integer data:";
            cin>>data;
            if(stack->push(data) == 1)
            {
                cout<<"Successfully push data %d into stack.\n";
            }
            else
            {
                cout<<"Failed to push data into stack.\n";
            }
        }
        else if(command.compare("pop") == 0) 
        {
            temp = stack->pop();
            if(temp == NULL)
            {
                cout<<"Failed to pop a data from stack.\n";
            }
            else
            {
                cout<<"Pop data %d from stack.\n"<<*temp;
            }
        }
    }
}