#include <iostream>
#include <cstring>

#define SIZE 3

using namespace std;

class Queue
{
public:
    Queue(){}

    int enqueue(int d)
    {   
        front++;
        if((front-back) < SIZE){    //check limit ordistance btwn front and back if its within
            int add = front % SIZE;
            data[add] = d;
            return 1;
        }
        front--;
        return -1;
    }
    int *dequeue()
    {
        
        if(front - back >= 0){
            int remove = back % SIZE;
            back++;
            return &data[remove];
        }
        return NULL;
    }
private:
    int data[SIZE]{};
    int front = -1, back = 0;
};

int main()
{
    int data, *temp;
    char command[50];
    Queue *queue = new Queue();
    while(1)
    {
        cin>>command;
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        else if(strcmp(command, "enqueue") == 0)
        {
            cout<<"Please input a integer data:";
            cin>>data;
            if(queue->enqueue(data) == 1)
            {
                cout<<"Successfully enqueue data "<<data<<" into queue."<<endl;
            }
            else
            {
                cout<<"Failed to enqueue data into queue."<<endl;
            }
        }
        else if(strcmp(command, "dequeue") == 0) 
        {
            temp = queue->dequeue();
            if(temp == NULL)
            {
                cout<<"Failed to dequeue a data from queue.\n";
            }
            else
            {
                cout<<"Dequeue data "<<*temp<<" from queue."<<endl;
            }
        }
    }
}