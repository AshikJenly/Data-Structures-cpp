#include<iostream>
using namespace std;

class Graph{
    private:
          int arr[10][10];
          int size,start;
    public:
            Graph()
              { 
                cout<<"\nEnter size : ";
                cin>>size;
                cout<<"\nEnter Adjacency Matrix =>\n";
                for(int i=0;i<size;i++){
                  for(int j=0;j<size;j++){
                    cin>>arr[i][j];
                  }
                }

                cout<<"\nEnter The vertex to start : ";
                cin>>start;
              }
              void DFS();

};
void Graph::DFS(){
  
//    1 =>   Declare a visited array and Initialize it
      int * visited=new int[size];
      for(int i=0;i<size;i++)
            visited[i]=0;
      
//     2 => Create a stack of size (size) 
      int stack[size],top=-1,index;

//    start push from starting index into stack
      index=stack[++top]=start;
      visited[index]=1;

      while(top>=0){
            index=stack[top];
            cout<<stack[top--]<<endl;

            for(int j=size-1;j>=0;j--){
                if(visited[j]!=1&&arr[index][j]!=0)
                        {
                          stack[++top]=j;
                          visited[j]=1;
                        }
            }



      }

}
int main(){

      Graph g1;
      cout<<"\nGraph Traversal DFS\n";
      g1.DFS();
}

