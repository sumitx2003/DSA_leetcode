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
    vector<string>ans;
    void solve(TreeNode* root,string str){
          if(root==NULL)return;

          str+=to_string(root->val)+"->";

          if(root->left==NULL && root->right==NULL){
            str.pop_back();
            str.pop_back();
               ans.push_back(str);
          }
          solve(root->left,str);
          solve(root->right,str);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str;
        solve(root,str);
        return ans;
    }
};