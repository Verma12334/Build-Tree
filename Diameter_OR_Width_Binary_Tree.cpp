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


// int diameter(node*root){
//      //base case
//     if(root==NULL){
//         return 0;
//     }
//     int op1=diameter(root->left);
//     int op2=diameter(root->right);
//     int op3=height(root->left)+1+height(root->right);

//     int ans=max(op1,max(op2,op3));
//     return ans;
// }//T.C.O(n2)...n=number of nodes/
// int main(){        
//     node*root=NULL;
//     buildFromLevelOrder(root);
//     cout<<"Height of Binary tree is: "<<height(root)<<endl;
//     cout<<"Diameter of Binary tree is: "<<diameter(root)<<endl;

// }


//2nd way


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

pair<int,int>diameterFast(node*root){
    //base case 
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int>left=diameterFast(root->left);
    pair<int,int>right=diameterFast(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;

    pair<int,int>ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;

    return ans;
    

}

int diameter(node*root){
    return diameterFast(root).first;
}//T.C.O(n)...n=number of nodes/


int main(){        
    node*root=NULL;
    buildFromLevelOrder(root);
    cout<<"Diameter of Binary tree is: "<<diameter(root)<<endl;

}