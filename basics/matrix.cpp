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
        r = c = 0;
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

    Matrix add(Matrix, Matrix);
    Matrix subtract(Matrix, Matrix);
    Matrix multiply(Matrix, Matrix);
    Matrix transpose();

    bool isDiagonal()
    {
        if (r != c)
            return false;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i != j && m[i][j] != 0)
                    return false;
            }
        }
        return true;
    }
    bool isIdentity()
    {
        if (r != c)
            return false;
        for (int i = 0; i < r; i++)
        {   for (int j = 0; j < c; j++)
            {    
                if ((i == j && m[i][j] != 1) ||(i != j && m[i][j] != 0))
                    return false;
            }
        }
        return true;
    }
};
Matrix Matrix::add(Matrix A, Matrix B)
{
    Matrix R;
    if (A.r != B.r || A.c != B.c)
    {
        cout << "Addition not possible...\n";
        return R;
    }
    R.r = A.r;
    R.c = A.c;
    for (int i = 0; i < R.r; i++)
        for (int j = 0; j < R.c; j++)
            R.m[i][j] = A.m[i][j] + B.m[i][j];
    return R;
}
Matrix Matrix::subtract(Matrix A, Matrix B)
{
    Matrix R;
    if (A.r != B.r || A.c != B.c)
    {
        cout << "Subtraction not possible...\n";
        return R;
    }
    R.r = A.r;
    R.c = A.c;
    for (int i = 0; i < R.r; i++)
        for (int j = 0; j < R.c; j++)
            R.m[i][j] = A.m[i][j] - B.m[i][j];
    return R;
}
Matrix Matrix::multiply(Matrix A, Matrix B)
{
    Matrix R;
    if (A.c != B.r)
    {
        cout << "Multiplication not possible...\n";
        return R;
    }
    R.r = A.r;
    R.c = B.c;
    for (int i = 0; i < R.r; i++)
        for (int j = 0; j < R.c; j++)
            for (int k = 0; k < A.c; k++)
                R.m[i][j] += A.m[i][k] * B.m[k][j];
    return R;
}
Matrix Matrix::transpose()
{
    Matrix T;
    T.r = c;
    T.c = r;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T.m[j][i] = m[i][j];
    return T;
}

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
        cout << "\n7. Identity Check";
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
            R = R.add(A, B);
            R.showData();
            break;
        case 3:
            A.getdata();
            B.getdata();
            R = R.subtract(A, B);
            R.showData();
            break;
        case 4:
            A.getdata();
            B.getdata();
            R = R.multiply(A, B);
            R.showData();
            break;
        case 5:
            A.getdata();
            R = A.transpose();
            R.showData();
            break;
        case 6:
            A.getdata();
            cout << (A.isDiagonal() ? "Diagonal Matrix\n" : "Not Diagonal\n");
            break;
        case 7:
            A.getdata();
            cout << (A.isIdentity() ? "Identity Matrix\n" : "Not Identity\n");
            break;
        case 8:
            cout << "EXITING PROGRAM...\n";
            break;
        default:
            cout << "INVALID CHOICE\n";
        }
    } while (ch != 8);
    return 0;
}
