#include<iostream>
#include<queue>
using namespace std;

class BinaryTree{
    public:
    int data;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

BinaryTree* buildTree(BinaryTree *root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root=new BinaryTree(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Creating left child for "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Creating right child for "<<data<<endl;
    root->right=buildTree(root->right);

    return root;

}
/*
Traversals:
    Inorder Traversal: LNR (Left Node Right)
    Preorder Traversal: NLR (Node Left Right)
    Postorder Traversal: LRN (Left Right Node)
*/

void inorderTraversal(BinaryTree *root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<"\t";
    inorderTraversal(root->right);
}

void preorderTraversal(BinaryTree *root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<"\t";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(BinaryTree *root){
    if(root==NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<"\t";
}

void levelOrdertraversal(BinaryTree* root){
    queue<BinaryTree*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
       BinaryTree* temp=q.front();
       q.pop();

       if(temp==NULL){
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
       }

       else{
       cout<<temp->data<<"\t";
       if(temp->left){
        q.push(temp->left);
       }
       if(temp->right){
        q.push(temp->right);
       }
       } 
    }
    
}

void buildFromLevelOrder(BinaryTree* &root){
    queue<BinaryTree*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root=new BinaryTree(data);
    q.push(root);

    while(!q.empty()){
        BinaryTree* temp=q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new BinaryTree(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new BinaryTree(rightData);
            q.push(temp->right);
        }
    }
}

int main(){

    BinaryTree *root=NULL;
    // root=buildTree(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);
    cout<<endl;
    cout<<endl;
    cout<<"Printing Level of order"<<endl;
    levelOrdertraversal(root);
    cout<<"Inoder Traversal"<<endl;
    inorderTraversal(root);
    cout<<endl;
     cout<<"Preoder Traversal"<<endl;
    preorderTraversal(root);
    cout<<endl;
     cout<<"Postoder Traversal"<<endl;
    postorderTraversal(root);
    cout<<endl;
    return 0;
}