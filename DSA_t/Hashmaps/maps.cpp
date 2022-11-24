#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){

//  in unordered map 
    unordered_map<string,int> m;

    // Insertion sttles 
    // inserion in unordered map insert readomly
    pair<string,int> p=make_pair("Navpreet",3);
    m.insert(p);

    pair<string,int> p2("Singh",2);
    m.insert(p2);

    m["Sidhu"]=1;

cout<<m["Navpreet"]<<endl;
cout<<m.at("Sidhu")<<endl;

// this will give error: key not found
// cout<<m.at("unknownKey")<<endl;

// this will create a key with the value of 0
cout<<m["unknownKey"]<<endl;

//  this will output the value 0 as key is generated in line 26
cout<<m.at("unknownKey")<<endl;

cout<<"Size: "<<m.size()<<endl;

cout<<m.count("Ripan")<<endl;

cout<<m.count("Singh")<<endl;

// m.erase("Sidhu");

cout<<"Size: "<<m.size()<<endl;
cout<<endl;

cout<<"Unordered Map"<<endl;
// accessing map
for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
}
cout<<endl;
// accessing using iterator
unordered_map<string,int>::iterator it=m.begin();

while(it!=m.end()){
    cout<<it->first<<" "<<it->second<<endl;
    it++;
}

cout<<endl;
map<string,int> mp;

mp["Sidhu"]=1;

pair<string,int> x2("Singh",2);
mp.insert(x2);

pair<string,int> x=make_pair("Nav",3);
mp.insert(x);





cout<<"Map"<<endl;

for(auto i:mp){
    cout<<i.first<<" "<<i.second<<endl;
}
cout<<endl;

map<string,int>::iterator it2=mp.begin();
 while(it2!=mp.end()){
    cout<<it2->first<<" "<<it2->second<<endl;
    it2++;
}

return 0;

}