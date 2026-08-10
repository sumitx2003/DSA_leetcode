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
    bool ans=false;
    void solve(TreeNode* root,int targetSum){
        if(!root)return ;

        targetSum=targetSum-root->val;

        if(root->left==NULL && root->right==NULL && targetSum==0)ans=true;

        if(root->left){
            solve(root->left,targetSum);
        } 
        if(root->right){
            solve(root->right,targetSum);
        }

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
         solve(root,targetSum);
         return ans;
    }
};