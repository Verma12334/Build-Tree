 
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
    cout<<"Enter data for root: \n";
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


pair<bool,int>isSumTreeFast(node*root){
    //base case
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }

    if(root->left==NULL && root->right==NULL){
        if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
  }


    pair<bool,int>leftans=isSumTreeFast(root->left);
    pair<bool,int>rightans=isSumTreeFast(root->right);
    bool left=leftans.first;
    bool right=rightans.first;

    bool condn=root->data==leftans.second+rightans.second;

    pair<bool,int>ans;

    if(left&& right &&condn){
        ans.first=true;
        ans.second=2*root->data;
    }
    else{
        ans.first=false;
    }

    return ans;
}

bool isSumTree(node*root){
    return isSumTreeFast(root).first;
}

int main(){        
    node*root=NULL;
    buildFromLevelOrder(root);
  
   if(isSumTree(root)){
    cout<<"Binary tree is Sum tree \n";
   }
   else{
    cout<<"Binary tree is not Sum tree\n";

   }
}