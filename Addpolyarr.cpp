#include<iostream>
using namespace std;
int addpoly(int(&poly1)[10][2], int(&poly2)[10][2], int(&poly3)[10][2], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    while (1)
    {
        if (poly1[i][1] < poly2[j][1])
        {
            poly3[k][0] = poly2[j][0];
            poly3[k][1] = poly2[j][1];
            k++, j++;
        }
        else if (poly1[i][1] > poly2[j][1])
        {
            poly3[k][0] = poly1[i][0];
            poly3[k][1] = poly1[i][1];
            k++, i++;
        }
        else
        {
            poly3[k][0] = poly1[i][0] + poly2[j][0];
            poly3[k][1] = poly1[i][1];
            i++, j++, k++;
        }
        if (j == n2)
        {
            while (i < n1)
            {
                poly3[k][0] = poly1[i][0];
                poly3[k][1] = poly1[i][1];
                k++, i++;
            }
        }
        if (i == n1)
        {
            while (j < n2)
            {
                poly3[k][0] = poly2[j][0];
                poly3[k][1] = poly2[j][1];
                k++, j++;
            }
        }
        if (i == n1)
            break;
    }
    return k;
}
void display_poly(int(&poly)[10][2], int n)
{
    for (int i = 0;i < n - 1;i++)
        cout << poly[i][0] << "x^" << poly[i][1] << "  +  ";
    cout << poly[n - 1][0] << "x^" << poly[n - 1][1] << endl << endl;
}
void get_poly(int(&poly)[10][2], int& n)
{
    cout << "How many terms in polynomial:  ";
    cin >> n;
    cout << endl;
    cout << "Enter coefficient and exponent in decreasing order" << endl;
    for (int i = 0;i < n;i++)
    {
        cout << endl;
        cout << "Enter coefficient for term " << i + 1 << " :";
        cin >> poly[i][0];
        cout << "Enter exponent for term " << i + 1 << " :";
        cin >> poly[i][1];
    }
}
int main()
{
    int a[10][2], b[10][2], c[10][2], n1, n2, n3;
    cout << "ADDITION OF TWO POLYNOMIALS USING ARRAY\n";
    cout << "\nEnter First polynomial :\n";
    get_poly(a, n1);
    cout << "Polynomial 1:";
    display_poly(a, n1);
    cout << endl;
    cout << "Enter Second polynomial :\n";
    get_poly(b, n2);
    cout << "Polynomial 2:";
    display_poly(b, n2);
    n3 = addpoly(a, b, c, n1, n2);
    cout << "Addition of two polynomials" << endl;
    display_poly(c, n3);
    return 0;
}
