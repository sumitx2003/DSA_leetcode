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
    int MOD=1e9+7;
    long long totalsum=0;
    long long maxproduct=INT_MIN;

    long long solve(TreeNode* root){
        if(root==NULL)return 0;

        long long left=solve(root->left);
       long long right= solve(root->right);

        long long currsum=left+right+root->val;
        long long x=totalsum-currsum;
        maxproduct=max(maxproduct,x*currsum);
        return currsum;
    }
    void dfs(TreeNode* root){
        if(root==NULL)return ;

        totalsum+=root->val;

        dfs(root->left);
       dfs(root->right);
        
    }

    int maxProduct(TreeNode* root) {
        dfs(root);

       solve(root);

        return maxproduct%MOD;
    }
};