#include<iostream>
using namespace std;


int Fibonacci_Search(int array[], int size, int value)
{
    int fib,fib1,fib2,offset,i;
    fib2 = 0;
    fib1 = 1;
    fib = fib1 + fib2;
    while (fib <= size)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }
    offset = -1;
    while (fib > 1)
    {
        i = offset + fib2;
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
    return -1;
}

int main()
{
    int size,value;
    cout << "Enter the size of your array : ";
    cin >> size;
    
    int array[100];
    cout << "Enter the elements in sorted order : " << endl;
    for (int i = 0;i < size;i++)
    {
        cin >> array[i];
    }
    cout << "Enter the key value to be searched : ";
    cin >> value;

    int result = Fibonacci_Search(array, size, value);
    if (result >= 0)
    {
        cout << "The number was " << array[result] << " found at position " << result + 1<<endl;
    }
    else
    {
        cout << "The number " << value << " not found!!" << endl;
    }
    return 0;
}
