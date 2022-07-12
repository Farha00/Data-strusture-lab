#include<iostream>
using namespace std;

int Fibonacci_Search(int array[], int size, int value)
{
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;
    while (fib <= size)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }
    int offset = -1;
    while (fib > 1)
    {
        int i = offset + fib2;
        if (array[i] < value)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if(array[i]>value)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
        {
            return i;
        }
    }
}

int main()
{
    int a[] = { 10,20,30,40,50,60,70,80 };
    int value;
    cout << "Enter the value to be searched : ";
    cin >> value;
    int result = Fibonacci_Search(a, 8, value);
    if (result >= 0)
    {
        cout << "The number " << a[result] << " was found at position " << result + 1;
    }
    else
    {
        cout << "The number " << value << " not found!!" << endl;
    }
}
