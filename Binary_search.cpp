#include<iostream>
using namespace std;

int Binary_Search(int array[], int size, int value)
{
    int beg = 0;
    int end = size - 1;
    int mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
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

    int result = Binary_Search(array, size, value);
    if (result >= 0)
    {
        cout << "The number was " << array[result] << " found at position " << result + 1;
    }
    else
    {
        cout << "The number " << value << " not found!!" << endl;
    }
    return 0;
}
