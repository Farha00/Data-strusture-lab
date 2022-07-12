#include<iostream>
using namespace std;

int Ternary_Search(int array[], int size, int value)
{
    int beg = 0;
    int end = size - 1;
    while (beg <= end)
    {
        int mid1 = beg + (end - beg) / 3;
        int mid2 = end - (end - beg) / 3;
        if (array[mid1] == value)
        {
            return mid1;
        }
        else if (array[mid2] == value)
        {
            return mid2;
        }
        else if(value < array[mid1])
        {
            end = mid1 - 1;
        }
        else if (value > array[mid2])
        {
            beg = mid2 + 1;
        }
        else
        {
            beg = mid1 + 1;
            end = mid2 - 1;
        }
    }
    return -1;
}

int main()
{
    int a[] = { 1,2,3,4,5,6,7,8,9,10 };
    int value;
    cout << "Enter the value to be searched : ";
    cin >> value;
    int result = Ternary_Search(a, 10, value);
    if (result >= 0)
    {
        cout << "The number " << a[result] << " was found at position " << result + 1;
    }
    else
    {
        cout << "The number " << value << " not found!!" << endl;
    }
}
