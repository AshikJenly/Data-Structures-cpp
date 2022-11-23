#include<iostream>
using namespace std;

class Heap{

    int * arr,size;

    public:
          Heap(){
             cout<<"\nEnter Size of Array : ";
             cin>>size;
             arr=new int[size];
             for(int i=0;i<size;i++)
                {
                  cout<<"\nEnter element "<<i+1<<" : ";
                  cin>>arr[i];
                }
              cout<<"\nBefore Sorting \n";
              Display();
              HeapSort();
               cout<<"\nBefore Sorting \n";
              Display();
          }
          void swap(int *,int *);
          void Display();
          void Heapify(int ,int);
          void HeapSort();

};
void Heap::swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;

}
void Heap::Display(){
    cout<<"\nHeap is  => ";
    for(int i=0;i<size;i++){
      cout<<"  "<<arr[i];
    }
}
void Heap::Heapify(int size,int largest){

        int index=largest;
        int Lchild=2*index+1;
        int Rchild=2*index+2;

        if(Lchild<size &&arr[Lchild]>arr[largest])
            largest=Lchild;
        if(Rchild<size&&arr[Rchild]>arr[largest])
            largest=Rchild;
        
        if(largest!=index){
          swap(&arr[largest],&arr[index]);
           Heapify(size,largest);
        }

}
void Heap::HeapSort(){

        for(int i=size/2-1;i>=0;i--)
              Heapify(size,i);
        

        for(int i=size-1;i>=0;i--){
             swap(&arr[0],&arr[i]);
             Heapify(i,0);
        }


}
int main(){
  Heap h1;
  return 0;

}
