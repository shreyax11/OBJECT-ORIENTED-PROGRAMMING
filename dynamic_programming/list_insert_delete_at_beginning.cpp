#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		
		Node()
		{
			data=0;
			next= nullptr;
		}
		~Node()
		{
			cout<<"destructor of node class\n";
		}
};
class List
{
	Node *start;
	int count;
	public:
		List()
		{
			start = nullptr;
			count=0;
		}
		Node* createnode(int v)
		{
			Node *nn;
			nn = new Node;
			if(nn==nullptr)
			{
				cout<<"memory not allocated..\n";
				return nn;
			}
			nn->data=v;
			nn->next=nullptr;
			return nn;
		}
		void insert_at_beginning(int v)
		{
			Node *nn=createnode(v);
			if(start==nullptr)
			{
				start=nn;
				count++;
			}
			else
			{
				nn->next=start;
				start=nn;
				count++;
			}
		}
		void delete_at_beginning()
		{
			if(start==nullptr)
			{
				cout<<"list is empty..\n";
				return;
			}
			Node *temp;
			temp=start;
			start=start->next;
			cout<<"the deleted element from the list is "<<temp->data<<endl;
			delete temp;
			count--;
		}
		void nodecount()
		{
			cout<<"the total nodes are "<<count<<endl;
		}
		void display()
		{
			if(start==nullptr)
			{
				cout<<"list is empty\n";
				return;
			}
			Node *temp;
			temp=start;
			while(temp != nullptr)
			{
				cout<<temp->data<<"	";
				temp=temp->next;
			}
			cout<<endl;
		}
		~List()
		{
			Node *temp;
			while(start != nullptr)
			{
				temp=start;
				start=temp->next;
				delete temp;
			}
			cout<<"destructor of class list\n"; 
		}
};

int main()
{
    List obj;
    int ch;
    do
    {
        cout<<"\n----menu----\n";
        cout<<"1.Insert at beginning\n2.Delete at beginning\n3.Display\n4.Total nodes\n5.Exit\n";
        cout<<"Enter choice: ";
        cin >> ch;  
        
        if(ch<1 || ch>4)
      	{
      		break;
		}

        switch(ch)
        {
            case 1:
                int val;
                cout << "Enter value to insert: ";
                cin >> val;
                obj.insert_at_beginning(val);
                break;
            case 2:
                obj.delete_at_beginning();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                obj.nodecount();
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(1);
    return 0;
}





