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
     int solve(TreeNode* root){
        if(root==NULL)return 0;

        int left=solve(root->left);
        int right=solve(root->right);

        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
         if(root==NULL)return true;

         bool isleft=isBalanced(root->left);
         bool isright=isBalanced(root->right);

         bool diff=abs(solve(root->left)-solve(root->right))<=1;

         if(isleft && isright && diff)return true;

         return false;
    }
};