#include<iostream>
using namespace std;

int Binary_Search(int array[], int size, int value)
{
    int beg = 0;
    int end = size - 1;
    while (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (array[mid] == value)
        {
            return mid;
        }
        else if(array[mid] > value)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }
}

int main()
{
    int a[] = { 10,20,30,40,50,60,70,80 };
    int value;
    cout << "Enter the value to be searched : ";
    cin >> value;
    int result = Binary_Search(a, 8, value);
    if (result >= 0)
    {
        cout << "The number " << a[result] << " was found at position " << result + 1;
    }
    else
    {
        cout << "The number " << value << " not found!!" << endl;
    }
}
