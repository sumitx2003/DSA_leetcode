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
    string s1;
    string s2;
    void dfs(TreeNode* node){
        if(node->left==NULL && node->right==NULL){
            s1+=node->val+'0';
            return ;
        }

        if(node==NULL){
            s1+="*";
        }
        else{
            s1+=node->val+'0';
        }
        if(!node->left && node->right){
            s1+='*';
        }
    
        if(node->left)dfs(node->left);

         if(!node->right && node->left){
            s1+='*';
        }

        if(node->right)dfs(node->right);
    }
      void dfs1(TreeNode* node){
        if(node->left==NULL && node->right==NULL){
            s2+=node->val+'0';
            return ;
        }

        if(node==NULL){
            s2+="*";
        }
        else{
            s2+=node->val+'0';
        }

        if(!node->right && node->left)s2+='*';

        if(node->right)dfs1(node->right);

        if(!node->left && node->right)s2+='*';

        if(node->left)dfs1(node->left);

    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;

        if(!root->left && !root->right)return true;

        if((!root->left && root->right) || (root->left && !root->right))return false;

        s1="";
        s2="";

        dfs(root->left);
        dfs1(root->right);

        return s1==s2;
    }
};