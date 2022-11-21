#include<iostream>
using namespace std;
class Selection{
    private:
        int *arr;
        int size;
        void getData();
        void SelectionSort();
        void display();
    public:

          Selection(int n){
                arr=new int[n];
                size=n;
                getData();
                display();
                SelectionSort();
                display();
          }   
};
void Selection::getData(){
            cout<<"\nEnter Values of array =>\n";
            for(int i=0;i<size;i++){
                cout<<"\nElement "<<i+1<<" : ";
                cin>>arr[i];
            }
          }
void Selection::display(){
            cout<<"\nElements in the array =>\n";
            for(int i=0;i<size;i++){
              cout<<"  "<<arr[i];
            }
          }
void Selection::SelectionSort(){

   
  
  for(int i=0;i<size;i++){
      int max=0;
      int last=size-1-i;

      for(int j=0;j<=last;j++){
        if(arr[max]<arr[j])
            max=j;
      }
      int temp=arr[max];
      arr[max]=arr[last];
      arr[last]=temp;

  }


}
int main(){
  int x;
  cout<<"\nEnter size : ";cin>>x;
  Selection *s1=new Selection(x);
  
}