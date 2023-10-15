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
    vector<vector<int>> levelOrder(TreeNode* root) {
  
        vector<vector<int>>v;
        vector<int>temp;
        queue<TreeNode*>q;
        if(root==NULL){
          return v;
        }
          q.push(root);
         temp.push_back(root->val);
         v.push_back(temp);
         temp.clear();
      
        while(!q.empty()){
         TreeNode*a=q.front();
         if(a->left!=NULL){
             q.push(a->left);
               temp.push_back(a->left->val);
         }
           if(a->right!=NULL){
             q.push(a->right);
               temp.push_back(a->right->val);
         }
         if(temp.size()!=0){
         v.push_back(temp);
         temp.clear();
         }
         
         q.pop();
        }
        return v;
            }
};

//Level  order traversal with level no.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
  
        vector<vector<int>>v;
       
        queue<TreeNode*>q;
        if(root==NULL){
          return v;
        }
          q.push(root);
        while(!q.empty()){
         vector<int>temp;
         int b=q.size();
         for(int i=0;i<b;i++){
        TreeNode*a=q.front();
        q.pop();
         if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                temp.push_back(a->val);

         }
         v.push_back(temp);
        }
        return v;
            }
};