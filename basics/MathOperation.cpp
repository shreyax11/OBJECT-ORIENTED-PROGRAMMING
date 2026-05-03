#include <iostream>
#include <cmath> 
using namespace std;

class MathOperations 
{
public:
    void factorial(int n) 
    {
        long long fact = 1;
        for(int i = 1; i <= n; i++)
        {
            fact *= i;
        // print multiplication steps
            if(i != n)
                cout << i << " * ";
            else
                cout << i;
        }
        
        cout << "\nFactorial of " << n << " = " << fact<<endl;
    }
    void fibonacci(int n) 
    {
        int a = 0, b = 1, next;
        cout << "Fibonacci Series: ";
        for(int i = 1; i <= n; i++) 
        {
            cout << a << " ";     
            next = a + b;         
            a = b;                 
            b = next;              
        }
        cout << endl;
    }
    bool isPrime(int n) 
    {
        if(n <= 1) 
            return false;
        for(int i = 2; i <= n/2; i++) 
        {
            if(n % i == 0)
                return false;
        }
        return true;
    }

    
    bool isPalindrome(int n) 
    {
        int original = n, rev = 0, digit;
        while(n > 0) 
        {
            digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        return original == rev;
    }
    bool isArmstrong(int n) 
    {
        int original = n, sum = 0, digit, digits = 0;
        int temp = n;
        while(temp > 0) 
        {
            digits++;
            temp /= 10;
        }
        temp = n;
        while(temp > 0) 
        {
            digit = temp % 10;
            sum += pow(digit, digits);  
            temp /= 10;
        }
        return sum == original;
    }
};

int main() {
    MathOperations mo; 
    int choice, num;

    do 
    {
        cout << "\n=== MENU ===\n";
        cout << "1. Factorial\n";
        cout << "2. Fibonacci Series\n";
        cout << "3. Prime Number Checker\n";
        cout << "4. Palindrome Checker\n";
        cout << "5. Armstrong Number Checker\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) 
        {
            case 1:
                cout << "Enter a number: ";
                cin >> num;
                mo.factorial(num);
                break;
            case 2:
                cout << "Enter number of terms: ";
                cin >> num;
                mo.fibonacci(num);
                break;
            case 3:
                cout << "Enter a number: ";
                cin >> num;
                if(mo.isPrime(num))
                    cout << num << " is a Prime number.\n";
                else
                    cout << num << " is not a Prime number.\n";
                break;
            case 4:
                cout << "Enter a number: ";
                cin >> num;
                if(mo.isPalindrome(num))
                    cout << num << " is a Palindrome.\n";
                else
                    cout << num << " is not a Palindrome.\n";
                break;
            case 5:
                cout << "Enter a number: ";
                cin >> num;
                if(mo.isArmstrong(num))
                    cout << num << " is an Armstrong number.\n";
                else
                    cout << num << " is not an Armstrong number.\n";
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 6);
    return 0;
}
