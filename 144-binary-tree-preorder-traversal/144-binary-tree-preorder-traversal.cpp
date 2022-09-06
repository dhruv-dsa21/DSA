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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
     if(root==NULL){
       return ans;
     }
      TreeNode* node = root;
      
      stack<TreeNode*> st;
      st.push(node);
      while(!st.empty()){
       
        if(node!=NULL){
          ans.push_back(node->val);
            if(node->left!=NULL){
            st.push(node->left);
          }
          node = node->left;
        
          
         }else{
         node = st.top();
          st.pop();
          if(node->right!=NULL){
            st.push(node->right);
            
          }
          node = node->right;
        }
        
        
      }
      return ans;
    }
};