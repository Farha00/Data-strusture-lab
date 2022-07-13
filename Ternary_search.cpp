#include<iostream>
using namespace std;

int Ternary_Search(int array[], int size, int value)
{
    int beg = 0;
    int end = size - 1;
    int mid1,mid2;
    while (beg <= end)
    {
        mid1 = beg + (end - beg) / 3;
        mid2 = end - (end - beg) / 3;
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

    int result = Ternary_Search(array, size, value);
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
