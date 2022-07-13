#include<iostream>
using namespace std;

void Bubble_Sort(int array[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j<size-i-1;j++)
        {
            if (array[j] > array[j + 1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;        
                       
}
int main()
{
 int size;
 int ch;

 do
 {
    int count=0;
    int *array;
 cout<<"Enter the number of elements of the array: ";
 cin>>size;
 cout<<"Enter the elements of the array: ";
  for(count=0; count<size; count++)
  {
      cin>>array[count];
  }

  cout<<"Sorted list : ";
  Bubble_Sort(array,size);
 
 cout<<"\n";

 cout<<"Do you want to continue?"<<endl;
 cout<<"1:Yes\n2:No\nEnter your choice : ";
 cin>>ch;
 cout<<"\n";
 }while(ch!=2);
  return 0;
}
