#include <iostream>
using namespace std;

int maxOf(int m, int n) {
    if (m > n)
        return m;
    else
        return n;
}

int* add(int A[], int B[], int m, int n)
{
    int newSize = max(m, n);
    int* sum = new int[newSize];

    for (int i = 0; i < m; i++)
        sum[i] = A[i];

    for (int i = 0; i < n; i++)
        sum[i] += B[i];

    return sum;
}

void display(int poly[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << poly[i];
        if (i != 0)
            cout << "x^" << i;
        if (i != n - 1)
            cout << " + ";
    }
}

int main()
{
    int m, n;
    cout << "Enter the number of terms in first polynomial : ";
    cin >> m;
    cout << "Enter the coefficients of terms in the increasing order of power : \n";

    int A[10];
    for (int i = 0; i < m; i++)
        cin >> A[i];

    cout << "Enter the number of terms in second polynomial : ";
    cin >> n;
    cout << "Enter the coefficients of terms in the increasing order of power : \n";

    int B[10];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    cout << "First polynomial is \n";
    display(A, m);
    cout << "\nSecond polynomial is \n";
    display(B, n);

    int* sum = add(A, B, m, n);
    int size = max(m, n);

    cout << "\nSum polynomial is \n";
    display(sum, size);

    return 0;
}