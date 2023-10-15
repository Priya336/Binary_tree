#include<bits/stdc++.h>
using namespace std;

struct Node{
int val;
Node*right;
Node*left;
};
Node*CreatNode(int v){
    Node*newnode=(struct Node*)malloc(sizeof(Node));
    newnode->val=v;
    newnode->right=NULL;
    newnode->left==NULL;
    return newnode;
}
vector<int>top_view(Node*root){
    map<int,int>m;
    queue<pair<int,Node*>>q;
     vector<int>ans;
    if(root==NULL){
        return ans;
    }
   
    q.push({0,root});

    while(!q.empty()){
    pair<int,Node*>temp=q.front();
    q.pop();
    int d=temp.first;
    Node*p=temp.second;
    auto s=m.find(d);
    
        m[d]=p->val;
    
    if(root->left){
        q.push({d-1,root->left});
    }
    if(root->right){
        q.push({d+1,root->right});
    }
    }

    for(auto i:m){
        cout<<(i.second)<<endl;
        ans.push_back((i.second));
    }
    return ans;
}
int main(){
    Node*root=CreatNode(5);
    Node*root1=CreatNode(8);
    Node*root2=CreatNode(9);
    Node*root3=CreatNode(3);
    Node*root4=CreatNode(1);
    Node*root5=CreatNode(7);
    Node*root6=CreatNode(6);
    Node*root7=CreatNode(2);
    Node*root8=CreatNode(10);

    root->right=root1;
    root->left=root2;
    root2->left=root3;
    root2->right=root4;
    root3->left=root5;
    root5->right=root6;
    root4->left=root7;
    root1->right=root8;
    top_view(root);
    return 0;
}