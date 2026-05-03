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
		void area()
		{
			ar=a*b;
			cout<<"THE AREA OF ";
		}
		~Shape()
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
			Shape::area();
			cout<<"SQUARE IS "<<ar<<endl<<endl;
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
			Shape::area();
			cout<<"RECTANGLE IS "<<ar<<endl<<endl;
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
			Shape::area();
			cout<<"TRIANGLE IS "<<(ar)/2<<endl<<endl;
		}
		~Triangle()
		{
			cout<<"triangle destructor\n";
		}
};
int main()
{
	Square sq(4);
	sq.area();
	Rectangle r(2,3);
	r.area();
	Triangle t(2,3);
	t.area();
}
