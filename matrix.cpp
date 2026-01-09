#include <iostream>
using namespace std;
const int MAX = 10;
class Matrix
{
private:
    int m[MAX][MAX];
    int r, c;
public:
    Matrix()
    {
        r = 0;
        c = 0;
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                m[i][j] = 0;
    }
    void getdata()
    {
        cout << "Enter rows and columns: ";
        cin >> r >> c;
        cout << "Enter elements:\n";
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> m[i][j];
    }
    void showData()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
    }
    void add(Matrix A, Matrix B)
    {
        if (A.r != B.r || A.c != B.c)
        {
            cout << "Addition not possible...\n";
            return;
        }
        r = A.r;
        c = A.c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                m[i][j] = A.m[i][j] + B.m[i][j];
    }
    void subtract(Matrix A, Matrix B)
    {
        if (A.r != B.r || A.c != B.c)
        {
            cout << "Subtraction not possible...\n";
            return;
        }
        r = A.r;
        c = A.c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                m[i][j] = A.m[i][j] - B.m[i][j];
    }
    void multiply(Matrix A, Matrix B)
    {
        if (A.c != B.r)
        {
            cout << "Multiplication not possible...\n";
            return;
        }
        r = A.r;
        c = B.c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                m[i][j] = 0;
                for (int k = 0; k < A.c; k++)
                    m[i][j] += A.m[i][k] * B.m[k][j];
            }
    }
    void transpose(Matrix A)
    {
        cout << "\nTranspose Result:\n";
        for (int i = 0; i < A.c; i++)
        {
            for (int j = 0; j < A.r; j++)
                cout << A.m[j][i] << " ";
            cout << endl;
        }
    }
    void diagonal()
    {
        if (r != c)
        {
            cout << "Not a square matrix...\n";
            return;
        }
        int flag = 1;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (i != j && m[i][j] != 0)
                    flag = 0;
        if (flag)
            cout << "Matrix is a diagonal matrix.\n";
        else
            cout << "Matrix is not a diagonal matrix.\n";
    }
    void identity()
    {
        if (r != c)
        {
            cout << "Not a square matrix... cannot be identity.\n";
            return;
        }
        int flag = 1;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i == j && m[i][j] != 1)
                    flag = 0;
                else if (i != j && m[i][j] != 0)
                    flag = 0;
            }
        }
        if (flag == 1)
            cout << "Matrix is an identity matrix.\n";
        else
            cout << "Matrix is not an identity matrix.\n";
    }
};
int main()
{
    Matrix A, B, R;
    int ch;
    do
    {
        cout << "\n--- MATRIX MENU ---";
        cout << "\n1. Insert and Display";
        cout << "\n2. Addition";
        cout << "\n3. Subtraction";
        cout << "\n4. Multiplication";
        cout << "\n5. Transpose";
        cout << "\n6. Diagonal Check";
        cout << "\n7. Check Identity Matrix";
        cout << "\n8. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            A.getdata();
            A.showData();
            break;
        case 2:
            A.getdata();
            B.getdata();
            R.add(A, B);
            cout << "\nAddition Result:\n";
            R.showData();
            break;
        case 3:
            A.getdata();
            B.getdata();
            R.subtract(A, B);
            cout << "\nSubtraction Result:\n";
            R.showData();
            break;
        case 4:
            A.getdata();
            B.getdata();
            R.multiply(A, B);
            cout << "\nMultiplication Result:\n";
            R.showData();
            break;
        case 5:
            A.getdata();
            R.transpose(A);
            break;
        case 6:
            A.getdata();
            A.diagonal();
            break;
        case 7:
            A.getdata();
            A.identity();
            break;
        case 8:
            cout<<"EXITING THE PROGRAM....\n";
            break;
        default:
            cout<<"INVALID CHOICE..\n";
        }
    } while (ch != 8);
    return 0;
}
