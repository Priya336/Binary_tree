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
int maxi=-1;
int ans;
void sum(Node*root,int v,int s){
if(root==NULL){
    return ;
}
if(root->left==NULL && root->right==NULL){
if(maxi<v){
  maxi=v;
   ans=s+root->val;
    return;
}
}
sum(root->left,v+1,s+root->val);
sum(root->right,v+1,s+root->val);
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
     sum(root,0,0);
    cout<<ans<<"\n";
    return 0;
}