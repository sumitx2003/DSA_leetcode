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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL)return root;

        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && node->right){
                    q.push(node->left);
                    q.push(node->right);
                    TreeNode* temp=node->left;
                    node->left=node->right;
                    node->right=temp;
                }
                else if(node->left && !node->right){
                    q.push(node->left);
                    node->right=node->left;
                    node->left=NULL;
                }
                else if(!node->left && node->right){
                    q.push(node->right);
                    node->left=node->right;
                    node->right=NULL;
                }
            }
        }
        return root;
    }
};