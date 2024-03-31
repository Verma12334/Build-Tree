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

void levelorderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();

        if(temp==NULL){
            //purana level complete traverse ho choka hai
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


void buildFromLevelOrder(node*&root){
    queue<node*>q;
    cout<<"Enter data for root\n";
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();

        cout<<"Enter left node for:"<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
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


int main(){
    node*root=NULL;

    //creation a Tree 
    root=buildTree(root);//entre 1 3 7 -1 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelorderTraversal(root);
    cout<<endl;

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

