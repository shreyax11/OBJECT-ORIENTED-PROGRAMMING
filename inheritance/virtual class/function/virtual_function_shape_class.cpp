#include<iostream>
using namespace std;
class Shape
{
	protected:
	int a,b,ar;
	
	public:
		Shape(int x, int y)
		{
			a=x;
			b=y;
			cout<<"shape constructor\n";
		}
		virtual void area()=0;
		virtual ~Shape()
		{
			cout<<"shape destructor\n";
		}
};
class Square: public Shape
{
	public:
		Square(int x):Shape(x,x)
		{
			cout<<"square constructor\n";
		}
		void area()
		{
			cout<<"THE AREA OF SQUARE IS "<<a*a<<endl<<endl;
		}
		~Square()
		{
			cout<<"square destructor\n";
		}
};
class Rectangle: public Shape
{
	public:
		Rectangle(int x,int y):Shape(x,y)
		{
			cout<<"rectangle constructor\n";
		}
		void area()
		{
			cout<<"THE AREA OF RECTANGLE IS "<<a*b<<endl<<endl;
		}
		~Rectangle()
		{
			cout<<"rectangle destructor\n";
		}
};
class Triangle: public Shape
{
	public:
		Triangle(int x,int y):Shape(x,y)
		{
			cout<<"triangle constructor\n";
		}
		void area()
		{
			cout<<"THE AREA OF TRIANGLE IS "<<(a*b)/2<<endl<<endl;
		}
		~Triangle()
		{
			cout<<"triangle destructor\n";
		}
};
int main()
{
	Shape *s;
	Square sq(4);
	s=&sq;
	s->area();
	Rectangle r(2,3);
	s=&r;
	s->area();
	Triangle t(2,3);
	s=&t;
	s->area();
}
