#include<iostream>
#include<string>
using namespace std;
class book
{
	string name,author,id;
	char type;
	public:
		static int txtcount,refcount,count;
		book()
		{
			count++;
		}
		
		void getdata()
		{
			cout<<"Enter the name of the book: ";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter the author of the book: ";
			getline(cin,author);
			cout<<"Enter the book type(T for textbook and R for reference): ";
			cin>>type;
			if(type =='T'||type == 't')
			{
				txtcount++;
				id = "TXT"+strg(txtcount);
			}
			else if(type =='R'||type == 'r')
			{
				refcount++;
				id = "REF"+strg(refcount);
			}
			else
			{
				cout<<"Invalid input. Default to textbook"<<endl;
				txtcount++;
				id = txtcount;
			}
		}
		void showdata()
		{
			cout<<"Book name: "<<name<<endl;
			cout<<"Author name: "<<author<<endl;
			if(type =='T'||type == 't')
			{
				cout<<"Book ID: "<<id<<endl;
			}
			else if(type =='R'||type == 'r')
			{
				cout<<"Book ID: "<<id<<endl;
			}
		}
		string strg(int n)
		{
			int num = n,nd=0;
			string str = "";
			while(num>0)
			{
				nd++;
				num = num/10;
			}
			while(nd<3)
			{
				str += "0";
				nd++;
			}	
			str += to_string(n);
			return str;
		}
};

int book::txtcount=0;
int book::refcount=0;
int book::count=0;

int main()
{
	int n;
	cout<<"Enter the no of books: ";
	cin>>n;
	book b[n];
	int ch,count=0;
	do
	{
		cout<<"\n*--MENU--*"<<endl;
		cout<<"1.Enter book details\n2.print detalis\n3.Display total book count\n4.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				while(count<n)
				{
					b[count].getdata();
					count++;
				}
				if(count > n)
					cout<<"\n Maximum "<<n<<" books allowed"<<endl;
				break;
			case 2:
				if(count == 0)
					cout<<"\n No book data available"<<endl;
				else
				{
					for(int i = 0; i<count;i++)
						b[i].showdata();
				}
				break;
			case 3:
				cout<<"Total textbooks: "<<book::txtcount<<endl;
				cout<<"Total reference books: "<<book::refcount<<endl;
				cout<<"Total books: "<<book::count<<endl;
				break;
			case 4:
				exit(0);
			default:
				cout<<"Invalid choice"<<endl;
		}
	}while(1);
	return 0;
}
