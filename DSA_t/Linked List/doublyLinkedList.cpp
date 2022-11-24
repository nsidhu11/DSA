#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

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

void insertAtHead(int data,Node* &head, Node* &tail){

    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=head;
    }

    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;

}

void insertAtTail(Node* &head,Node* &tail, int data){

    if(tail==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=head;
    }

    Node * temp =new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

int getLength(Node* &head){
    Node* temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

void insertAtIndex(Node* &head,Node* &tail, int data,int index){
    if(index==1){
        insertAtHead(data,head,tail);
        return;
    }

    Node* temp=head;
    int i=1;

    while(index<i){
        temp=temp->next;
        i++;
    }

    if(temp->next==NULL){
        insertAtTail(head,tail,data);
        return;
    }

    Node* newNode=new Node(data);
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}

void deleteIndex(Node* &head,int index){
    if(index==1){
        Node* temp=head;
        head=temp->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    Node* curr=head;
    Node* back=NULL;

    int i=1;
    while(i<index){
        back=curr;
        curr=curr->next;
        i++;
    }

    curr->prev=NULL;
    back->next=curr->next;
    curr->next->prev=back;
    curr->next=NULL;

    delete curr;


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
    Node* head=node1;
    Node* tail=node1;
    print(head);

    insertAtHead(20,head,tail);
    insertAtHead(30,head,tail);
    insertAtHead(40,head,tail);
     print(head);

     insertAtTail(head,tail,50);
    print(head);
insertAtIndex(head,tail,35,2);
print(head);

deleteIndex(head,1);
print(head);



    return 0;
}