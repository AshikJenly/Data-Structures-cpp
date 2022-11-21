#include<iostream>
using namespace std;

typedef struct Node{
    int data;
     struct Node*next;
}Node;

class Hashing{
        private:
              Node ** Hash_Table;
        
        public:
              Hashing();
              int hash_function(int data);
              void insert(int data);
              void search(int data);
              void deleteValue(int data);

};
Hashing::Hashing(){
    Hash_Table=new Node*[10];
    	for(int i=0;i<10;i++)
            Hash_Table[i]=NULL;
}
      
int Hashing::hash_function(int data){
	return data%10;
}

void Hashing::insert(int data){
        int index=hash_function(data);
        Node * table_index=Hash_Table[index];
        Node *new_node=new Node();
        new_node->data=data;
        new_node->next=NULL;

        if(table_index==NULL)
                 Hash_Table[index]=new_node;
        else {
                while(table_index->next!=NULL)
                              table_index=table_index->next;

                table_index->next=new_node;
             }
        cout<<"\nInserted "<<data<<endl;

}
void Hashing::search(int data){

      int index=hash_function(data);

      Node *temp=Hash_Table[index];

       while(temp!=NULL){
             if(temp->data==data)
             		cout << data << " is Found.\n";
                      return ;
              temp=temp->next;
       }
       cout << data << " is not found.\n";
}
void Hashing::deleteValue(int data){
        int index=hash_function(data);
        Node * table_index=Hash_Table[index];
        Node * prev=NULL;
        if(table_index==NULL)
        {
            cout<<"\nElement Not Found";
            return;
        }     
       if(table_index->data==data){
                  Hash_Table[index]=NULL;
                  cout<<"\nDeleted "<<data<<endl;
       }
       else{
            prev=table_index;
            while(table_index!=NULL){
                  
                  if(table_index->data==data){
                        prev->next=table_index->next;
                        cout<<"\nDeleted "<<data<<endl;
                  }
                  prev=table_index;
                  table_index=table_index->next;
            }
       }
}
int main(){
	Hashing h1;
	int choice, key;
	do{
		cout << "Hashing:";cout<< "\n1.Insert\n2.Search\n3.Remove\n4.Exit.\n";
		cout<< "Enter your choice : ";cin >> choice;
		switch(choice){
			case 1:
				cout << "Enter key to be inserted : ";cin >> key;
				h1.insert(key);
				break;
			case 2:
				cout << "Enter the key to be searched : ";cin >> key;
				h1.search(key);
				break;
			case 3:
				cout << "Enter the key value to delete : ";cin >> key;
				h1.deleteValue(key);
				break;
			case 4:
				cout << "Exiting the program. ";
				break;
			default:
				cout << "Enter valid numbers. ";
				break;
		}
	}while(choice != 4);
	return 0;
}
