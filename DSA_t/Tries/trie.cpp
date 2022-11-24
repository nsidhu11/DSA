#include<iostream>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    char data;
    bool isTermianl;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }     
        isTermianl=false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root=new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length()==0){
            root->isTermianl=true;
            return;
        }

        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child= root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word){

        if(word.length()==0){
            return root->isTermianl;
        }

        int index=word[0]-'A';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child,word.substr(1));

    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }
};

int main(){

    Trie* t=new Trie();

    t->insertWord("Navpreet");
    t->insertWord("Singh");
    t->insertWord("Sidhu");

    cout<<"Present or Not "<<t->searchWord("Nav")<<endl;

    return 0;
}