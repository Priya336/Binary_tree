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
vector<int>right_view(Node*root,int level){
    vector<int>ans;
if(root==NULL){
    return ans;
}
if(level==ans.size()){
    ans.push_back(root->val);
    cout<<root->val<<endl;
}

right_view(root->right,level+1);
right_view(root->left,level+1);
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
   right_view(root,0);
    return 0;
}