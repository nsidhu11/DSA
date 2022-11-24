/*
operations in stack:
    1. push
    2. pop
    3. peak/top
    4. isEmpty
*/

#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> s;

    s.push(2);
    s.push(3);

    s.pop();

    cout<<"top element is: "<<s.top()<<endl;
    

    if(s.empty()){
        cout<<"Empty Stack"<<endl;
    }
    else{
        cout<<"Satck is not empty"<<endl;
    }

    return 0;
}
