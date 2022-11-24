#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node * next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }

        cout<<"Memory Free for node with data "<<value<<endl;
    }
};

void insertNode(Node* &head,int element,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        newNode->next=newNode;
        return;
    }

    Node* curr=head;
   
    while (curr->data!=element)
    {
        curr=curr->next;
        if(curr==head){
            cout<<"Element "<<element<<" not found"<<endl;
            return;
        }
    }

    Node* temp=new Node(data);
    temp->next=curr->next;
    curr->next=temp;
}

void deleteNode(Node* &head,int data){
    if(head==NULL){
        cout<<"List is Empty!!"<<endl;
        return;
    }

    Node* prev=head;
    Node* curr= prev->next;

    while (curr->data!=data)
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr==prev){
        head=NULL;
    }
    else if(head==curr){
        head=prev;
    }
    prev->next=curr->next;
    curr->next=NULL;

    delete curr;
    
}

void print(Node* &head){
    if(head==NULL){
        cout<<"Empty List!!"<<endl;
        return;
    }
    Node* temp=head;
    do{
        cout<<head->data<<"\t";
        head=head->next;
    }while(head!=temp);
    cout<<endl;
}

int main(){
    Node* head=NULL;
   insertNode(head,5,3);
   print(head);

    insertNode(head,3,5);
   print(head);

// insertNode(head,5,7);
//    print(head);

// insertNode(head,7,9);
//    print(head);

//    insertNode(head,8,40);
//    print(head);

   deleteNode(head,3);
   print(head);
    return 0;
}