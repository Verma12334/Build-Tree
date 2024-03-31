// #include<iostream>
// #include<queue>
// using namespace std;

// class node {
//     public:
//     int data;
//     node*left;
//     node*right;

//     node(int d){
//         this->data=d;
//         this->left=NULL;
//         this->right=NULL;
//     }
// };

// void buildFromLevelOrder(node*&root){
//     queue<node*>q;
//     cout<<"Enter data for root: \n";
//     int data;
//     cin>>data;
//     root=new node(data);
//     q.push(root);

//     while(!q.empty()){
//         node*temp=q.front();
//         q.pop();

//         cout<<"Enter left node for:"<<temp->data<<endl;
//         int leftData;
//         cin>>leftData;

//         if(leftData!=-1){
//             temp->left=new node(leftData);
//             q.push(temp->left);
//         }
//         cout<<"Enter right node for: "<<temp->data<<endl;
//         int rightData;
//         cin>>rightData;

//         if(rightData!=-1){
//             temp->right=new node(rightData);
//             q.push(temp->right);
//         }
//     }
// }

// int height(node*root){
//     //base case
//     if(root==NULL){
//         return 0;
//     }

//     int left=height(root->left);
//     int right=height(root->right);

//     int ans=max(left,right)+1;
//     return ans;
// } 


// bool balance_tree(node*root){
//      //base casee
//     if(root==NULL){
//         return true;
//     }
//     bool left=balance_tree(root->left);
//     bool right=balance_tree(root->right);
//     bool diff=abs(height(root->left)-height(root->right))<=1;

//     if(left&&right&&diff){
//         return true;
//     }
//     else{
//         return false;
//     }
// }//T.C.O(n2)...n=number of nodes/


// int main(){        
//     node*root=NULL;
//     buildFromLevelOrder(root);
//    if(balance_tree(root)){
//     cout<<"Binary tree is Balance tree\n";
//    }
//    else{
//     cout<<"Binary tree is not Balance tree\n";

//    }
// }

// 2nd way 
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
pair<bool,int>balancefast(node*root){
    //base case
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }

    pair<int,int>left=balancefast(root->left);
    pair<int,int>right=balancefast(root->right);

    bool leftans=left.first;
    bool rightans=right.first;

    bool diff=abs(left.second-right.second)<=1;

    pair<bool,int>ans;

    ans.second=max(left.second,right.second)+1;

    if(leftans&& rightans&& diff){
        ans.first=1;
    }
    else{
        ans.first=false;
    }

    return ans;
}

bool balance_tree(node*root){
    return balancefast(root).first;
}//T.C.O(n2)...n=number of nodes/


int main(){        
    node*root=NULL;
    buildFromLevelOrder(root);
   if(balance_tree(root)){
    cout<<"Binary tree is Balance tree\n";
   }
   else{
    cout<<"Binary tree is not Balance tree\n";

   }
}