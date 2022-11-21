#include<iostream>
using namespace std;
class QuickSort{
      private:
        int *arr,size;
      public:
          QuickSort(){
              cout<<"\nEnter Size of Array : ";
              cin>>size;
              getData();
              cout<<"\nBefore Sorting \n";
              display();
              sort(0,size-1);
              cout<<"\nAfter Sorting \n";
              display();
              }
         
          void getData();
          void sort(int,int);
          void swap(int *,int *);
          void display();
};
void QuickSort::getData(){
      for(int i=0;i<size;i++){
        cout<<"\nEnter element "<<i+1<<" : ";
        cin>>arr[i];
      }
   }
void QuickSort::swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;

}
void QuickSort::sort(int low,int high){
        
        if(low>=high)return;

        int start=low;
        int end=high;
        int mid=start+(end-start)/2;
        int pivot =arr[mid];

        while(start<=end){

              while(arr[start]<pivot)
                    start++;
              while(arr[end]>pivot)
                     end--;

              if(start<=end){
                  swap(&arr[start],&arr[end]);
                  start++;
                  end--;
                }

           
        }

               sort(low,end);
               sort(start,high);

}
void QuickSort::display(){
    cout<<"\nElements are =>\n";
    for(int i=0;i<size;i++){
      cout<<" "<<arr[i];
    }
}

int main(){
  QuickSort q1;
  return 0;

}