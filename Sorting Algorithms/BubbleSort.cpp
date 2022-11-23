#include<iostream>
using namespace std;
class BubbleSort{
      private:
        int *arr,size;
      public:
          BubbleSort(){
              cout<<"\nEnter Size of Array : ";
              cin>>size;
		  arr=new int[size];
              getData();
              cout<<"\nBefore Sorting \n";
              display();
              sort();
              cout<<"\nAfter Sorting \n";
              display();
              }
         
          void getData();
          void sort();
          void swap(int *,int *);
          void display();
};
void BubbleSort::getData(){
      for(int i=0;i<size;i++){
        cout<<"\nEnter element "<<i+1<<" : ";
        cin>>arr[i];
      }
   }
void BubbleSort::swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;

}
void BubbleSort::sort(){
        int flag=0;
      for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
              if(arr[j]>arr[j+1])
                {
                  flag=1;
                  swap(&arr[j],&arr[j+1]);
                }
        }
        if(!flag)
            {cout<<"\nAlready Sorted ";return;}
      }

}
void BubbleSort::display(){
    cout<<"\nElements are =>\n";
    for(int i=0;i<size;i++){
      cout<<" "<<arr[i];
    }
}

int main(){
  BubbleSort q1;
  return 0;

}