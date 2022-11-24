#include<iostream>
using namespace std;

class Circularqueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    CircularQueue(int n){
        size=100001;
        arr=new int[size];
        front=rear=-1;
    }

    bool enqueue(int value){
        if((fornt==0 && rear==size-1) ||(rear==(front-1)%(size-1))){
            cout<<"Queue is Full"<<endl;
            return false;
        }
        else if(fornt ==-1){
            front=rear=0;
        }
        else if(rear==size-1 && front!=0 ){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=value;
        return true;
    }

    int dequeue(){
        if(front==-1){
            cout<<"Queue is Empty"<<endl;
        }
        int ans =arr[fornt];
        arr[fornt]=-1;
        if(fornt==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
    }
};