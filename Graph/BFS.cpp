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
              void BFS();

};

void Graph::BFS(){

          int * visited =new int[size];
          for(int i=0;i<size;i++)
                visited[i]=0;
            

          int queue[size],front=0,rear=0;

          int index=start;

          visited[index]=1;
          queue[rear++]=index;

          while(front!=rear){

                  index=queue[front++];
                  cout<<index<<endl;

                  for(int j=0;j<size;j++){

                        if(arr[index][j]!=0 &&visited[j]!=1)
                        {
                          visited[j]=1;
                          queue[rear++]=j;

                        }
                  }
          }




}
int main(){

      Graph g1;
      cout<<"\nGraph Traversal DFS\n";
      g1.BFS();
}

/*
0 1 1 0 0 
1 0 0 1 0 
1 0 0 1 1 
0 1 1 0 1 
0 0 1 1 0 
 
*/