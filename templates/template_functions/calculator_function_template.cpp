#include <iostream>
using namespace std;

template <typename T, typename U>
auto add(T a, U b)
{
    return a + b;
}

template <typename T, typename U>
auto sub(T a, U b) 
{
    return a - b;
}

template <typename T, typename U>
auto mul(T a, U b) 
{
    return a * b;
}

template <typename T, typename U>
auto divi(T a, U b) 
{
    if(b == 0) 
    {
        cout << "Error: Division by zero\n";
        return 0;
    }
    return a / b;
}

int main() 
{
    // int, int
    cout << "int + int: " << add(10, 5) << endl;

    // int, float
    cout << "int + float: " << add(10, 2.5) << endl;

    // float, float
    cout << "float + float: " << add(2.5, 3.5) << endl;

    return 0;
}