#include <iostream>
using namespace std;

#define MAX 5

// Base Class: Queue
template <class T>
class Queue 
{
protected:
    int front, rear;
    T arr[MAX];

public:
    Queue() 
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty() 
    {
        return (front == -1);
    }

    virtual bool isFull() 
    {
        return (rear == MAX - 1);
    }

    virtual void enqueue(T x) 
    {
        if (isFull()) 
        {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
    }

    virtual void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        front++;
        if (front > rear)
            front = rear = -1;
    }

    virtual void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Derived Class: Cqueue
template <class T>
class Cqueue : public Queue<T> 
{
public:
    bool isFull() 
    {
        return ((this->rear + 1) % MAX == this->front);
    }

    void enqueue(T x) 
    {
        if (isFull()) 
        {
            cout << "Cqueue Overflow\n";
            return;
        }

        if (this->front == -1)
            this->front = this->rear = 0;
        else
            this->rear = (this->rear + 1) % MAX;

        this->arr[this->rear] = x;
    }

    void dequeue() 
    {
        if (this->isEmpty()) 
        {
            cout << "Cqueue Underflow\n";
            return;
        }

        cout << "Deleted: " << this->arr[this->front] << endl;

        if (this->front == this->rear)
            this->front = this->rear = -1;
        else
            this->front = (this->front + 1) % MAX;
    }

    void display() 
    {
        if (this->isEmpty()) 
        {
            cout << "Queue Empty\n";
            return;
        }

        int i = this->front;

        do 
        {
            cout << this->arr[i] << " ";
            i = (i + 1) % MAX;
        } while (i != (this->rear + 1) % MAX);

        cout << endl;
    }
};

int main() 
{
    Queue<int> q;
    Cqueue<int> cq;

    Queue<int>* ptr;

    int type, choice, val;

    do 
    {
        cout << "\n1. Queue\n2. Cqueue\n3. Exit\n";
        cout << "Enter type: ";
        cin >> type;

        if (type == 3)
            break;

        switch (type) 
        {
        case 1:
            ptr = &q;
            break;

        case 2:
            ptr = &cq;
            break;

        default:
            cout << "Invalid type\n";
            continue;
        }

        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            ptr->enqueue(val);
            break;

        case 2:
            ptr->dequeue();
            break;

        case 3:
            ptr->display();
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (true);

    return 0;
}