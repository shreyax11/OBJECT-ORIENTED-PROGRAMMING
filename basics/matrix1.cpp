#include<iostream>
using namespace std;
const int MAX = 10;
class matrix
{
	int m[MAX][MAX];
	int r,c;
	public :
		matrix()//constructor
		{
			r=0;
			c=0;
			for(int i=0; i<MAX;i++)
			{
				for(int j=0;j<MAX; j++)
					m[i][j]=0;
			}
		}
		void getdata()
		{
			cout<<"enter the rows:";
			cin>>r;
			cout<<"enter the columns:";
			cin>>c;
			cout<<"enter the elements of the matrix:\n";
			for(int i=0; i<r;i++)
			{
				for(int j=0;j<c; j++)
					cin>>m[i][j];
			}
		}
		void showdata()
		{
			cout<<"\nthe elements of the matrix are:\n";
			for(int i=0; i<r;i++)
			{
				for(int j=0;j<c; j++)
					cout<<m[i][j]<<" ";
				cout<<endl;
			}
		}
		void add(matrix A, matrix B)
		{
			if(A.r != B.r && A.c != B.c)
			{
				cout<<"addition is not possible..\n";
				return;
			}
			r= A.r;
			c= B.c;
			for(int i=0; i<r;i++)
			{
				for(int j=0;j<c; j++)
					m[i][j]= A.m[i][j]+B.m[i][j];
			}
		}
		void sub(matrix A, matrix B)
		{
			if(A.r != B.r && A.c != B.c)
			{
				cout<<"subtraction is not possible..\n";
				return;
			}
			r= A.r;
			c= B.c;
			for(int i=0; i<r;i++)
			{
				for(int j=0;j<c; j++)
					m[i][j]= A.m[i][j]-B.m[i][j];
			}
		}
		void multiply(matrix A, matrix B)
		{
			if(A.c != B.r)
			{
				cout<<"multiplication is not possible..\n";
				return;
			}
			r= A.r;
			c= B.c;
			for(int i=0; i<r;i++)
			{
				for(int j=0;j<c; j++)
					for(int k=0; k<A.r; k++)
						m[i][j] += A.m[i][k]*B.m[k][j];
			}
		}
		void transpose()
		{
			cout<<"\ntranspose matrix is :\n";
			for(int i=0; i<c;i++)
			{
				for(int j=0;j<r; j++)
					cout<<m[i][j]<<" ";
				cout<<endl;
			}
		}
		bool isdiagonal()
		{
			for(int i=0; i<c;i++)
			{
				for(int j=0;j<r; j++)
				{
					if(i != j && m[i][j] != 0)
					{
						return false;
					}
				}
			}
			return true;
		}
};
int main()
{
	matrix A,B,R;
	int ch;
	do
	{
		cout<<"\n---MATRIX MENU---\n";
		cout<<"1.ADDITION\n2.SUBTRACTION\n3.MULTIPLICATION\n4.TRANSPOSE\n5.CHECK DIAGONAL MATRIX\n6.EXIT\n";
		cout<<"ENTER YOUR CHOICE:\n";
		cin>>ch;
		if(ch >=1 && ch<=3)
		{
			cout<<"\nfirst matrix...\n";
			A.getdata();
			cout<<"\nsecond matrix...\n";
			B.getdata();
		}
		switch(ch)
		{
			case 1:
				R.add(A,B);
				R.showdata();
				break;
			case 2:
				R.sub(A,B);
				R.showdata();
				break;
			case 3:
				R.multiply(A,B);
				R.showdata();
				break;
			case 4:
				A.getdata();
				A.showdata();
				A.transpose();
				break;
			case 5:
				A.getdata();
				A.showdata();
				if(A.isdiagonal())
					cout<<"matrix is diagonal matrix.\n";
				else
					cout<<"matrix is not a diagonal matrix\n";
				break;
			case 6:
				exit(0);
			default:
				cout<<"invalid choice...\n";
		}
	}while(1);
	return 0;
}
