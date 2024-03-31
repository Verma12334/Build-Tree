#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node*buildTree(node*root){  // by recursion
    cout<<"Enter the data: \n";
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){  // base case
        return NULL;
    }
    
    cout<<"Enter data for inserting in left "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
void inorder(node*root){
    //base case
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(node*root){
    //base case
    if(root==NULL){
        return;
    }


    preorder(root->left);
    preorder(root->right);
      cout<<root->data<<" ";
}

void postorder(node*root){
    //base case
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    postorder(root->left);
    postorder(root->right);
    
}

void CountLeafNode(node* root, int &count){
    //base case
    if(root==NULL){
        return;
    }

    CountLeafNode(root->left, count);

    //leaf node
    if(root->left==NULL && root->right==NULL){
        count++;
    }

    CountLeafNode(root->right, count);

}


int main(){
    node*root=NULL;
    int cnt=0;
    //creation a Tree 
    root=buildTree(root);//entre 1 3 7 -1 -1 -1 11 -1 -1 5 17 -1 -1 -1
    CountLeafNode(root,cnt);
    cout<<endl<<"No. of leaf node="<<cnt<<endl;

    cout<<"In-order traversal is: "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Pre-order traversal is:\n";
    preorder(root);
    cout<<endl;

    cout<<"Post-order traversal is:\n";
    postorder(root);
    cout<<endl;
}

