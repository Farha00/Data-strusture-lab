
#include<iostream>
using namespace std;


class Array_Operation
{
  public:
	void insertion(int array[],int size);
	void deletion(int array[],int size);
};
void Array_Operation::insertion(int array[],int size)
{
  int pos,value;
  
  cout<<"Enter the element you want to insert : ";
  cin>>value;
  cout<<"Enter the position at which you want to insert the element : ";
  cin>>pos;
  cout<<"\n";
 int J = size;
 do
 {
    array[J+1]= array[J];
    J=J-1;
 }while(J>=pos-1);

 array[pos-1] = value;
 size=size+1;
 for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}
void Array_Operation::deletion(int array[],int size)
{
  int value,pos;
  
  cout<<"Enter the position at which you want to delete : ";
  cin>>pos;
  value=array[pos];
  for(int j=pos;j<size;j++)
  {
    array[j-1]=array[j];
  }
  size=size-1;
  for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}
int main()
{
  Array_Operation B;
  int size,ch;
  cout<<"Enter the number of elements of the array :";
  cin>>size;
  int array[size];
  cout<<"Enter the elements of the array : ";
  for(int i=0;i<size;i++)
   {
     cin>>array[i];
   }
  cout<<"\n"; 
  
  do{
      cout<<"Select the operation you want to perform"<<endl;
      cout<<"1:Insertion\n2:Deletion\n3:Exit\nEnter your choice: ";
      cin>>ch;
      cout<<"\n";
      switch(ch)
      {
      case 1: B.insertion(array, size);
              size=size+1;
              cout<<"\n";
              break;
      case 2: B.deletion(array, size);
              size=size-1;
              cout<<"\n";
              break;
      case 3: break;       
      }
  }while(ch!=3);

}
