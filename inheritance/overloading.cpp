#include<iostream>

using namespace std;

int add(int a, int b)
{
	return a+b;
}
float add(float a, float b)
{
	return a+b;
}
int main()
{
	int a,b,c,ch;
	float x,y,z;
	do
	{
		cout<<"\n---MENU of Addition---"<<endl;
		cout<<"1.addition of intergers \n2.addition of floats\n3.exit\n";
		cout<<"enter your choice:"<<endl;
		cin>>ch;
		switch(ch)	
		{
			case 1:
				cout<<"enter two integer numbers:";
				cin>>a>>b;
				c=add(a,b);
				cout<<"addition of two interger is:"<<c;
				break;
			case 2:
				cout<<"enter two float numbers:";
				cin>>x>>y;
				z=add(x,y);
				cout<<"addition of two floats is:"<<z;
				break;
			case 3:
				exit(0);
			default:
				cout<<"invalid choice..."<<endl;	
		}
	}while(1);
}
