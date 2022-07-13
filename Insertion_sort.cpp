#include<iostream>
using namespace std;

void Insertion_Sort(int array[], int size) 
{
   int temp,k,ptr;
   for(k=1;k<size;k++)
   {
       temp=array[k];
       ptr=k-1;
       while(temp<array[ptr])
       {
           array[ptr+1]=array[ptr];
           ptr=ptr-1;
       }
      array[ptr+1]=temp;
   }
    
    
    for(int i = 0; i<size; i++)
    {
      cout << array[i] << " ";

    }
    cout << endl;
}
int main()
{
 int size;
 int ch;

 do
 {
    int cnt=0;
    int *array;
 cout<<"Enter the number of elements of the array you want to sort : ";
 cin>>size;
 cout<<"Enter the elements of the array : ";
  for(cnt=0; cnt<size; cnt++)
  {
      cin>>array[cnt];
  }
  cout<<"Sorted list : ";
  Insertion_Sort(array,size);

 cout<<"Do you want to continue?"<<endl;
 cout<<"1:Yes\n2:No\nEnter your choice : ";
 cin>>ch;
 cout<<"\n";
 }while(ch!=2);
  return 0;
}  
