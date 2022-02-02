#include <iostream>
#include <string>

using namespace std;

class Node
{
    public:
	    int data;
	    Node *next;
};

class Queue
{
public:
	Queue(){}

	int enqueue(int data)
	{
        
        if((top==NULL) && (bot==NULL)){
            bot = new Node();
            bot->data = data;
            bot->next = NULL;
            top = bot;  //make top and bot the same
            return 1;
        }else if(bot != NULL){
            Node *temp = new Node();
            temp->data = data;
            temp->next = NULL;
            top->next = temp;
            top = temp;
            return 1;
        }
        return -1;
	}
	int *dequeue()
	{
        
        if(bot != NULL){
            Node *temp = new Node();
            temp = bot;
            bot = bot->next;
            return &(temp->data);
        }
        return NULL;
	}
private:
	Node *top = NULL, *bot = NULL;
};

int main()
{
	int data, *temp;
	string command;
	Queue *queue = new Queue();
	while(1)
	{
		cin>>command;
		if(command.compare("exit") == 0)
		{
			break;
		}
		else if(command.compare("enqueue") == 0)
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
		else if(command.compare("dequeue") == 0) 
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