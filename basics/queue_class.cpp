#include<iostream>
using namespace std;

const int MAX = 10;

class Queue
{
    int arr[MAX];
    int front, rear;

public:

    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if(rear == MAX - 1)
            cout<<"Queue Overflow\n";
        else
        {
            if(front == -1)
                front = 0;

            rear++;
            arr[rear] = x;
        }
    }

    void dequeue()
    {
        if(front == -1 || front > rear)
            cout<<"Queue Underflow\n";
        else
        {
            cout<<"Deleted element: "<<arr[front]<<endl;
            front++;
        }
    }

    void display()
    {
        if(front == -1 || front > rear)
            cout<<"Queue is empty\n";
        else
        {
            cout<<"Queue elements: ";
            for(int i = front; i <= rear; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
};

int main()
{
    Queue q;
    int choice, x;

    do
    {
        cout<<"\n1. Enqueue";
        cout<<"\n2. Dequeue";
        cout<<"\n3. Display";
        cout<<"\n4. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter element: ";
                cin>>x;
                q.enqueue(x);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout<<"Exit\n";
                break;

            default:
                cout<<"Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}