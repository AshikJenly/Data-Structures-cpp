#include<iostream>
using namespace std;
typedef struct Node{
    int data;
    Node *LNode,*RNode;

}Node;
class BST{
   private:
      Node *root;

   public:
      BST(){root=nullptr;}
      void Insert(int);
      void Preorder(Node*);
      void Inorder(Node*);
      void Postorder(Node*);
      Node *getRoot(){return root;}
      ~BST() {delete root;}

};
void BST::Insert(int x){

    //1st Create a Node named temp
        Node *temp=new Node();
        temp->data=x;
        temp->LNode=nullptr;
        temp->RNode=nullptr;


        if(root==NULL){
            root=temp;
            return;
            }
        else  {
            //find the position 
            Node*prev,*current;
            current=root;

            while(current!=NULL){

                    prev=current;
                    if(current->data==x)
                            return;
                    else if(current->data>x)
                            current=current->LNode;
                    else 
                            current=current->RNode; 
                    }
            //prev node  reached the position,Now insert it
            if(prev->data>x)
                    prev->LNode=temp;
            else
                    prev->RNode=temp;
                            
            }
}
void BST::Preorder(Node *temp)
{
    if(temp!=NULL)
    {
        cout<<"-> "<<temp->data<<" ";
        Preorder(temp->LNode);
        Preorder(temp->RNode);
    }
}
/*Inorder Traversals*/
void BST::Inorder(Node *temp)
{
    if(temp!=NULL)
    {
        Inorder(temp->LNode);
        cout<<"-> "<<temp->data<<" ";
        Inorder(temp->RNode);
    }
}
/*Postorder Traversals*/
void BST::Postorder(Node *temp)
{
    if(temp!=NULL)
    {
        Postorder(temp->LNode);
        Postorder(temp->RNode);
        cout<<"-> "<<temp->data<<" ";
    }
}

int main()
{
    BST B; int ch;
 
    while(1)
    {
    // clrscr();
        cout<<"\n\t\t\tBinary Search Tree";
        cout<<"\n\t\t\t ~~~~~~~~~~~~~~~~~~";
        cout<<"\n1-Create";
        cout<<"\n2-Preorder";
        cout<<"\n3-Inorder";
        cout<<"\n4-Postorder";
        cout<<"\n5-Display";
        cout<<"\n6-Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>ch;


            switch(ch) {
                    case 1:
                        cout<<"\nEnter elements1 by1:(0to stopentering)\n";
                        int x;
                        do
                        {
                            cin>>x;
                            B.Insert(x);
                        }while(x!=0);
                    case 2:
                         cout<<"\n~~~~ PreOrder Traversal ~~~~ \n\nThe Tree is:\n";
                         B.Preorder(B.getRoot());
                         break;
                    case 3:
                         cout<<"\n~~~Inorder Traversal~~~\n\nThe Tree is:\n";
                         B.Inorder(B.getRoot());
                         break;
                    case 4:
                        cout<<"\n~~~Postorder Traversal~~~\n\nThe Tree is:\n";
                        B.Postorder(B.getRoot());
                        break;
                    case 5:
                        cout<<"\n~~~~~DISPLAY~~~~~~~\n\n";
                        break;
                    case 6:
                        cout<<"\n~~~Exit~~~\n";
                        // getch();
                        return 0;
                    default:
                            cout<<"\nEnter between 1 to5\n\n";
                            break;
            }
    }

}