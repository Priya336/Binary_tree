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

Node*LCA(Node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
 
    if(root->val==n1 || root->val==n2){
        return root;
    }
    Node*a=LCA(root->left,n1,n2);
     Node*b=LCA(root->right,n1,n2);
     if(a!=NULL && b!=NULL){
        return root;
     }
    if(a==NULL && b==NULL){
        return NULL;
    }
     else{
         if(a!=NULL){
             return a;
         }
         else{
             return b;
         }
     }
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
   Node*ans=LCA(root,2,6);
   cout<<ans->val;
    return 0;
}