/*
Binary Search Tree:
    Similar to binary tree. 
    Right child is greater than perent -- every node that is right of parent
    Left child is smaller than parent -- every node that is left of parent
*/

#include<iostream>
#include<queue>
using namespace std;

class BST{
    public:
    int data;
    BST *left;
    BST *right;

    BST(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

BST* insertIntoBST(BST* &root,int data){
    if(root==NULL){
        root=new BST(data);
        return root;
    }

    if(data>root->data){
        root->right=insertIntoBST(root->right,data);
    }
    else{
        root->left=insertIntoBST(root->left,data);
    }

    return root;
}

void takeInput(BST* &root){
    int data;
    cin>>data;

    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}
/*
// recursive method for search in BST
bool searchInBST(BST* root, int x){
    if(root==NULL){
        return false;
    }

    if(root->data==x){
        return true;
    }

    if(root->data>x){
        return searchInBST(root->left,x);
    }
    else{
        return searchInBST(root->right,x);
    }
}*/

// Iterative method of search in BST

bool searchInBST(BST* &root,int x){
    BST* temp=root;

    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }

    return false;
}

//  inorder of BSt is sorted
void inorderTraversal(BST *root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<"\t";
    inorderTraversal(root->right);
}

void preorderTraversal(BST *root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<"\t";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(BST *root){
    if(root==NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<"\t";
}

void levelOrdertraversal(BST* root){
    queue<BST*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
       BST* temp=q.front();
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

/*
left leaf of BST will always contain the minimum value
*/
BST* minVal(BST* &root){
    BST *temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

/*
right leaf of BST will always be the maximum value
*/
BST* maxVal(BST* &root){
    BST *temp=root;

    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

BST* deleteBSTNode(BST* &root,int x){

    if(root==NULL){
        return root;
    }

    if(root->data==x){

        //  No child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        
        // 1 Child
        if(root->left!=NULL && root->right==NULL){
            BST* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            BST* temp=root->right;
            delete root;
            return temp;
        }
        
        // 2 child
        if(root->left!=NULL & root->right!=NULL){
            int min =minVal(root->right)->data;
            root->data=min;
            root->right=deleteBSTNode(root->right,min);
            return root;
        }

    }
    else if(root->data>x){
        root->left=deleteBSTNode(root->left,x);
        return root;
    }
    else{
        root->right=deleteBSTNode(root->right,x);
        return root;
    }

}
int main(){

BST* root=NULL;
cout<<"Enter data to create BST"<<endl;

takeInput(root);

cout<<"Printing BST"<<endl;
levelOrdertraversal(root);

cout<<"Printing Inorder"<<endl;
inorderTraversal(root);
cout<<endl;

cout<<"Printing Preorder"<<endl;
preorderTraversal(root);
cout<<endl;

cout<<"Printing Postorder"<<endl;
postorderTraversal(root);
cout<<endl;

if(searchInBST(root,5)){
    cout<<"5 found in BST"<<endl;
}
else{
    cout<<"5 not found in BST"<<endl;
}

if(searchInBST(root,89)){
    cout<<"89 found in BST"<<endl;
}
else{
    cout<<"89 not found in BST"<<endl;
}

cout<<"Minimum Value is "<<minVal(root)->data<<endl;

cout<<"Maximum Value is "<<maxVal(root)->data<<endl;

cout<<"After deletion"<<endl;
deleteBSTNode(root,50);
levelOrdertraversal(root);

    return 0;
}