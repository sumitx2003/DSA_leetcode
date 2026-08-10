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
    vector<vector<int>>res;
    void solve(TreeNode* root,int targetSum,vector<int>&temp){
          if(!root)return;

          targetSum=targetSum-root->val;
          temp.push_back(root->val);
          if(root->left==NULL && root->right==NULL && targetSum==0){
                res.push_back(temp);
          }
          solve(root->left,targetSum,temp);
          solve(root->right,targetSum,temp);

          temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        solve(root,targetSum,temp);
        return res;
    }
};