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
   int count;
    void solve(TreeNode* root,long long targetSum,bool flag){
        if(!root)return;

        if(targetSum-root->val==0)count++;;


        if(flag==false){
            solve(root->left,targetSum,flag);
            solve(root->right,targetSum,flag);
            solve(root->left,targetSum-root->val,true);
            solve(root->right,targetSum-root->val,true);
        }
        else{
            solve(root->left,targetSum-root->val,true);
            solve(root->right,targetSum-root->val,true);
        } 
       
    }
    int pathSum(TreeNode* root, int targetSum) {
       count=0;
       solve(root,targetSum,false);
       return count;
      
    }
};