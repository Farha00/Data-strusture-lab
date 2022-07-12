#include<iostream>
using namespace std;

int Linear_Search(int array[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
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
    cout << "Enter the elements : " << endl;
    for (int i = 0;i < size;i++)
    {
        cin >> array[i];
    }
    cout << "Enter the key value to be searched : ";
    cin >> value;

    int result = Linear_Search(array, size, value);
    if (result >= 0)
    {
        cout << "The number was " << array[result] << " found at position " << result + 1;
    }
    else
    {
        cout << "The number " << value << "not found!!" << endl;
    }
    return 0;
}
