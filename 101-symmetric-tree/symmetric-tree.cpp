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
         string s1="";
         string s2="";
    void dfs(TreeNode* root){
        if(root==NULL){
            s1+="*";
            return ;
        }
        s1+=to_string(root->val);

        dfs(root->left);
        dfs(root->right);

    }
    void dfs1(TreeNode* root){
        if(root==NULL){
            s2+="*";
            return ;
        }
        s2+=to_string(root->val);

        dfs1(root->right);
        dfs1(root->left);

    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
         
         dfs(root->left);
         dfs1(root->right);

         if(s1==s2)return true;

         return false; 
    }
};