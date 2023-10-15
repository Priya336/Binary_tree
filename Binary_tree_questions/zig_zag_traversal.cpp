/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
       queue<TreeNode*>q;
       if(root==NULL){
          return v;
        }
       q.push(root);
      bool left_to_right=true;
       while(!q.empty()){
             cout<< left_to_right<<endl;
         
           int a=q.size();
             vector<int>temp(a);
           for(int i=0;i<a;i++){
               TreeNode*node=q.front();
               int index=left_to_right?i:a-i-1;
               temp[index]=node->val;
               q.pop();
                     if(node->left!=NULL){
                   q.push(node->left);}
                    if(node->right!=NULL){
                   q.push(node->right);}
           }
         
            left_to_right=(!left_to_right);
            v.push_back(temp);
       }
       return v;
    }
    
};