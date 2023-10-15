#include<bits/stdc++.h>
using namespace std;

void leaf_node(TreeNode*root,vector<int>*ans){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->val<<endl;
        ans.push_back(root->val);
        return;
    }
    leaf_node(root->left,ans);
    leaf_node(root->right,ans);
}
void left(TreeNode*root,vector<int>*ans){

    if((root->left==NULL &&root->right==NULL)||root==NULL){
        return ;
    }
    if(root->left==NULL && root->right!=NULL){
        cout<<root->val;
        ans.push_back(root->val);
        left(root->right,ans);
    }
     cout<<root->val;
        ans.push_back(root->val);
    left(root->left,ans);
}
void right(TreeNode*root,vetcor<int>*ans){
   
      if((root->left==NULL &&root->right==NULL)||root==NULL){
        return ;
    }
    if(root->right==NULL && root->left!=NULL){      
        left(root->left,ans);
    }
    else{
    left(root->right,ans);
    }
     cout<<root->val;
        ans.push_back(root->val);
    
}
void boundary_traversal(TreeNode *root,vector<int>ans){
    // TreeNoe*temp=root;
    // while(temp->left!=NULL ||temp->right!=NULL){
    // cout<<temp->val<<" ";
    // ans.push_back(temp->val);
    // if(temp->left==NULL && temp->right!=NULL){
    //   temp=temp->right;
    // }
    // else{
    //     temp=temp->left;
    // }
    // }
    left(root,ans);
    leaf_node(root,ans);
    right(root->right,ans);
}