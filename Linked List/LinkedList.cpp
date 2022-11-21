#include<iostream>
using namespace std;
typedef struct  node
{
    int data;
    struct node*ptr;
}node;

class LinkedList{
        private:
            node*head;
            int count=0;
        public:
            LinkedList(){head=nullptr;}
            void Append(int);
            void AddAfter(int,int);
            void AddAtBegin(int);
            void Display(int );
            void Count();
            void Delete(int);
            void Reverse();
            ~LinkedList(){
                 delete[]head;
            }
};
void LinkedList::Append(int x){
    //Create a node first
        node*new_node=new node();
        new_node->data=x;
        new_node->ptr=nullptr;

        if(!head)
            head=new_node;
        else
            {
                //initialize a temp pointer to traverse the list 
                node*temp=head;
                while(temp->ptr)
                    temp=temp->ptr;
                //temp pointer had reached the last node of the list 
                temp->ptr=new_node;
                 
            }

}
void LinkedList::AddAfter(int loc ,int x){
    
        node*new_node=new node(),*temp;
        new_node->data=x;
        new_node->ptr=nullptr;
    //First check if there is any existing node
        temp=head;
        if(!temp){
                cout<<"\n\tThere  are less than "<<loc<<" nodes in the list "<<endl;
                delete[]new_node;}
        else
             {
                if(loc==1){
                        this->AddAtBegin(x);
                        return;}
   //If there any nodes available ,lets start traversing
                for(int i=1;i<loc;i++){
                     if(!temp){
                            cout<<"\n\tThere  are less than "<<loc<<" nodes in the list "<<endl;
                            delete[]new_node;
                            return;
                            }
                        temp=temp->ptr;
                    }
                new_node->ptr=temp->ptr;
                temp->ptr=new_node;
      }
}

void LinkedList::AddAtBegin(int x){
        node*new_node=new node();
        new_node->data=x;
        new_node->ptr=head;
        head=new_node;
            
}
void LinkedList::Display(int flag=1){
            node*temp=head;
            count=0;
            //count variable used to count the number of nodes
            if(flag)
                cout<<"\nNodes are => \n\t\t";
            while(temp)
                    {  
                         if(flag)
                            cout<<temp->data<<"--> ";
                        temp=temp->ptr;
                        count++;
                    }
                    cout<<" NULL";
                    cout<<endl;
}
void LinkedList::Count(){
        //count is a member of the class
        this->Display(0);
        cout<<"There are "<<count<<" nodes in the list \n";
}
void LinkedList::Delete(int x){
        node*temp=head,*prev_node;
        while(temp){
             if(temp->data==x)
                {
                    if(temp==head){
                        head=head->ptr;
                        delete[]temp;
                        return;
                        
                    }
                    else{

                         prev_node->ptr=temp->ptr;
                         delete[]temp;
                         return;
                    }
                }
        prev_node=temp;
        temp=temp->ptr;
        }
cout<<"\n\n\tInvalid data \n";
}
void LinkedList::Reverse(){
    node*current=head,*prev=nullptr,*next=nullptr;
         while(current){
               next=current->ptr;
               current->ptr=prev;
               prev=current;
               current=next;
         }
         head=prev;
}         
int main(){
LinkedList L; int choice,value,loc;
 do
 {
    cout<<"\n\t\t\t Singly Linked List";
    cout<<"\n\t\t\t~~~~~~~~~~~~~~~~~~";
    cout<<"\n\t1. CREATE A NODE";
    cout<<"\n\t2.ADD AT THE BEGINING";
    cout<<"\n\t3. ADD AT END";
    cout<<"\n\t4. ADD AFTER A SPECIFIC LOCATION";
    cout<<"\n\t5. DISPLAY ";
    cout<<"\n\t6. COUNT NO OF NODES";
    cout<<"\n\t7. DELETE A SPECIFIED NODE";
    cout<<"\n\t8. REVERSE THE LIST";
    cout<<"\n\t9. EXIT";
    cout<<"\n\n\n Enter your choice : ";
    cin>>choice;
  switch(choice)
        {
        case 1 :
            cout<<"\n Enter a value : ";
            cin>>value;
            L.Append(value);
            L.Display();
            break;
        case 2 :
            cout<<"\n Enter a value : ";
            cin>>value;
            L.AddAtBegin(value);
            L.Display();
            break;
        case 3 :
            cout<<"\n Enter a value : ";
            cin>>value;
            L.Append(value);
            L.Display();
            break;
        case 4 :
            cout<<"\n Enter the location : ";
            cin>>loc;
            cout<<"\n Enter a value : ";
            cin>>value;
            L.AddAfter(loc,value);
            L.Display();
            break;
        case 5 :
            L.Display();
            break;
            case 6 :
            L.Count();
            L.Display();
            break;
        case 7 :
            cout<<"\n Enter a value to delete : ";
            cin>>value;
            L.Delete(value);
            L.Display();
            break;
        case 8:
            cout<< "\n The list before reversal is: \n";
            L.Display();
            L.Reverse();
            cout<<"\n The reversed list is: \n";
            L.Display();
            break;
        case 9 :
            cout<<"\n\n\n\t\t You are on Exit . . . ";
            break;

        }
        }
while(choice!=9);

return 0;
}

