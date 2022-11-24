#include<iostream>
#include<queue>

using namespace std;

int main(){

    // macx heap
    priority_queue<int> pq;
    
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Top Element"<<pq.top()<<endl;
    pq.pop();
    cout<<"Top Element"<<pq.top()<<endl;
    cout<<"Size"<<pq.size()<<endl;


    // min heap
    priority_queue< int, vector<int>,greater<int> > minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"Top Element"<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Top Element"<<minheap.top()<<endl;
    cout<<"Size"<<minheap.size()<<endl;

    return 0;

}