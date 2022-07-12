#include<iostream>
using namespace std;

int Interpolation_Search(int array[], int size, int value)
{
    int beg = 0;
    int end = size - 1;
    while (beg <= end)
    {
        int pos = beg + ((value - array[beg]) / (end - beg)) / (array[end] - array[beg]);
        if (array[pos] == value)
        {
            return pos;
        }
        else if (array[pos] > value)
        {
            end = pos - 1;
        }
        else
        {
            beg = pos + 1;
        }
    }
    return -1;
}

int main()
{
    int a[] = {2,6,9,13,18,23,44,76,89,91 };
    int value;
    cout << "Enter the value to be searched : ";
    cin >> value;
    int result = Interpolation_Search(a, 10, value);
    if (result >= 0)
    {
        cout << "The number " << a[result] << " was found at position " << result + 1;
    }
    else
    {
        cout << "The number " << value << " not found!!" << endl;
    }
}
