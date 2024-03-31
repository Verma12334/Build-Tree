 
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


bool isIdentical(node*r1,node*r2){
    //base case
    if(r1==NULL &&r2==NULL){
        return true;
    }
    if(r1==NULL &&r2!=NULL){
        return false;
    }
    if(r1!=NULL &&r2==NULL){
        return false;
    }

    bool left=isIdentical(r1->left,r2->left);
    bool right=isIdentical(r1->right,r2->right);
   
   bool value=r1->data==r2->data;

   if(left && right && value){
    return true;
   }
   else{
    return false;
   }
}//T.C.=O(n)

int main(){        
    node*root1=NULL;
    node*root2=NULL;
    cout<<"Enter nodes data for first tree\n";
    buildFromLevelOrder(root1);
    cout<<"Enter nodes data for second tree\n";
    buildFromLevelOrder(root2);
   if(isIdentical(root1,root2)){
    cout<<"Binary tree is Identical\n";
   }
   else{
    cout<<"Binary tree is not Indentical\n";

   }
}