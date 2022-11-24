#include<iostream>
#include<queue>
using namespace std;

int main(){

    deque<int> d;
    d.push_front(10);
    d.push_front(20);
    cout<<"Front: "<<d.front()<<endl;
    cout<<"Back: "<<d.back()<<endl;

    if(d.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    return 0;
}