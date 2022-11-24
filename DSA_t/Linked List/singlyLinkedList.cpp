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

void insertAtHead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;

}

void insertAtIndex(Node* &head,Node* &tail,int index,int data){
    if(index==1){
        insertAtHead(head,data);
        return;
    }

    Node* temp=head;
    int i=1;
    while (i<index-1)
    {
        temp=temp->next;
        i++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,data);
    }

    Node* newNode=new Node(data);
    newNode->next=temp->next;
    temp->next=newNode;

}

void deleteAtIndex(int index,Node* &head){
    if(index==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{

        Node* curr=head;
        Node* prev=NULL;
        int i=1;

        while (i<index)
        {
            prev=curr;
            curr=curr->next;
            i++;
        }
        
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    
    Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node* head=node1;
    Node* tail=node1;
    // print(head);

    insertAtTail(tail,12); 
    // insertAtHead(head,12);  
    // print(head);

    insertAtTail(tail,15);  
    //   insertAtHead(head,15); 
 insertAtTail(tail,25);
  insertAtTail(tail,35);
   insertAtTail(tail,45);
    print(head);

    insertAtIndex(head,tail,3,20);
    print(head);
    deleteAtIndex(3,head);
    print(head);

    cout<<"HEAD: "<<head->data<<" Tail: "<<tail->data<<endl;

    return 0;
}