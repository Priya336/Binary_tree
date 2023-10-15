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

vector<int> diagonal(Node*root){
    map<int,map<int,vector<int>>>m;
 queue<pair<Node*,pair<int,int>>>q;
   vector<int>ans;
   if(root==NULL){
    return ans;
   }
   q.push(make_pair(root,make_pair(0,0)));
   while(!q.empty()){
    pair<Node*,pair<int,int> >temp=q.front();
    q.pop();
    Node*frontNode=temp.first;
    int hd=temp.second.first;
    int lvl=temp.second.second;
    m[hd][lvl].push_back(frontNode->val);
    if(frontNode->left){
      q.push(make_pair(frontNode->left,make_pair(hd+1,lvl+1)));
    }
    if(frontNode->right){
 q.push(make_pair(frontNode->right,make_pair(hd,lvl+1)));
    }
   }
   for(auto i:m){
    for(auto j:i.second){
for(auto k:j.second){
    cout<<k<<endl;
    ans.push_back(k);
}
    }
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
    diagonal(root);
    return 0;
}