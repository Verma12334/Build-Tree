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

        cout<<"Enter left node for:"<<root->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for: "<<root->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
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


int main(){        //1 3 5 7 11 17 -1-1-1-1-1-1 -1
    node*root=NULL;
    buildFromLevelOrder(root);

    cout<<endl;
    levelorderTraversal(root);
    int count=0;
    cout<<endl;
    CountLeafNode(root,count);
    cout<<endl;
    cout<<"Number of leaf node="<<count;
    cout<<endl;
}