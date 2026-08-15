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
    vector<int>in;
    void solve(TreeNode* root){
        if(!root)return;

        solve(root->left);
        in.push_back(root->val);
        solve(root->right);
    }
    void solve1(TreeNode* root,int &i){
        if(!root)return;

        solve1(root->left,i);
        root->val=in[i];
        i++;
        solve1(root->right,i);
    }

    void recoverTree(TreeNode* root) {
        solve(root);
        sort(in.begin(),in.end());
        int i=0;
        solve1(root,i);
        
    }
};