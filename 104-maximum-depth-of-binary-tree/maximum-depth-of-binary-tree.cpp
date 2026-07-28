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
    int maxDepth(TreeNode* root) {
        int leftlevel=0;
        int rightlevel=0;
        if(root==NULL)return 0;

         queue<TreeNode*>q;

        if(root->left==NULL){
            leftlevel=0;
        }
        else if(root->left!=NULL){
            q.push(root->left);
            while(!q.empty()){
                int N=q.size();
                leftlevel++;
                while(N--){
                    TreeNode* node=q.front();
                    q.pop();

                    if(node->left)q.push(node->left);

                    if(node->right)q.push(node->right);
                }
            }
        }
        if(root->right==NULL){
            rightlevel=0;
        }
        else {
            q.push(root->right);

            while(!q.empty()){
                int N=q.size();
                rightlevel++;
                while(N--){
                    TreeNode* node=q.front();
                    q.pop();

                    if(node->left)q.push(node->left);

                    if(node->right)q.push(node->right);
                }
            }
        }

        return 1+max(leftlevel,rightlevel);
        
    }
};