#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int qFront  ;
    int rear;
    int size;

    public:
    Queue(){
        size=100001;
        arr=new int[size];
        qFront =0;
        rear=0;
    }

    void enqueue(int data){
        if(rear==size){
            cout<<"Queue is full";
        }
        else{
            arr[rear ]=data;
            rear++;
            }
        }
    int dequeue(){
        if(qFront ==rear){
            return -1;
        }
        else{
            int ans=arr[qFront ];
            arr[qFront ]=-1;
            qFront ++;
            if(qFront ==rear){
                qFront =0;
                rear=0;
            }
            return ans;
        }
    }

    int frontElement(){
        if(qFront ==rear){
            return -1;
        }
        else{
            return arr[qFront ];
        }
    }

    bool isEmpty(){
        if(qFront ==rear){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Queue q;

    if(q.isEmpty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<"qFront  : "<<q.frontElement()<<endl;

    q.dequeue();

    cout<<"qFront  : "<<q.frontElement()<<endl;

    if(q.isEmpty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
         cout<<"Queue is not empty"<<endl;
    }

    return 0;
}