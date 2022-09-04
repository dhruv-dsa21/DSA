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
   
    int finddia(TreeNode *root,int &maxi){
      if(root==NULL){
        return 0;
      }
   
     
        int p =  finddia(root->left,maxi);
     
    
        int q =  finddia(root->right,maxi);
      
      
     
       maxi = max(maxi,p+q);
      return 1 + max(p,q);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
          return 0;
        }
      int maxi = 0;
       finddia(root,maxi);
       return maxi;
      

    }
};