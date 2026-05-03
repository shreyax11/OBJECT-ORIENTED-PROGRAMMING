#include <iostream>
using namespace std;

// Priority: normal function > specialized template > generic template

// Generic Template
template <typename T>
void func(T a) 
{
    cout << "Generic Template\n";
}

// Specialized Template for int
template <>
void func<int>(int a) 
{
    cout << "Specialized Template (int)\n";
}

int main() {
    cout << "Call with int:\n";
    func(10);   

    cout << "\nCall with float:\n";
    func(5.5);  

    return 0;
}