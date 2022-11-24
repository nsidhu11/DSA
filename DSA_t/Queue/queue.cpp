#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout<<"Size of Queue: "<<q.size()<<endl;
    cout<<"Front is: "<<q.front()<<endl;

    q.pop();
    q.pop();

    cout<<"Size of Queue: "<<q.size()<<endl;
    cout<<"Front is: "<<q.front()<<endl;
    if(q.empty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    

    return 0;

}