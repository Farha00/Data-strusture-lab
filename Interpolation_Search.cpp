#include<iostream>
using namespace std;

int Interpolation_Search(int array[], int size, int value)
{
    int beg = 0;
    int end = size - 1;
    int pos;
    while (beg <= end)
    {
        pos = beg + ((value - array[beg]) / (array[end] - array[beg]) * (end - beg) );
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

    int result = Interpolation_Search(array, size, value);
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
