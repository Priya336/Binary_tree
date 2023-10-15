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
Node* solve(Node*root,int &k,int p){
    if(root==NULL){
    return NULL;
   }
    if(root->val==p ){
     
    return root;
  }
   
//left call
Node*a=solve(root->left,k,p);
//right call
Node*b=solve(root->right,k,p);
 if(a!=NULL && b==NULL){
       k--;
       if(k<=0){
           k=INT_MAX;
           return root;
       }
        return a;
    }

     
 if(a==NULL && b!=NULL){
       k--;
       if(k<=0){
           k=INT_MAX;
           return root;
       }
        return b;
    }

     
 return NULL;
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
    int k;
    cin>>k;
    int val;
    cin>>val;
    Node* ans=solve(root,k,val);
    if(ans==NULL && ans->val==root->val){
        cout<<-1<<endl;
    }
    else{
    cout<<ans->val<<endl;
    }
    return 0;
}