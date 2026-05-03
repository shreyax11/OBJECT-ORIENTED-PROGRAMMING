#include<iostream>
using namespace std;

class Stack
{
    int arr[10];
    int top;

public:

    // Default constructor
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if(top == 9)
            cout<<"Stack Overflow\n";
        else
        {
            top++;
            arr[top] = x;
        }
    }

    void pop()
    {
        if(top == -1)
            cout<<"Stack Underflow\n";
        else
        {
            cout<<"Deleted element: "<<arr[top]<<endl;
            top--;
        }
    }

    void display()
    {
        if(top == -1)
            cout<<"Stack is empty\n";
        else
        {
            cout<<"Stack elements:\n";
            for(int i=top;i>=0;i--)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();
    s.display();

    return 0;
}