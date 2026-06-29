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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int N=q.size();
            level++;
            while(N--){
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left)q.push(node->left);

                if(node->right)q.push(node->right);

            }
        }
        int count=0;
        q.push(root);
        while(!q.empty()){
            count++;
            int N=q.size();
            if(count==level){
                TreeNode* temp=q.front();
                return temp->val;
            }
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left)q.push(node->left);

                if(node->right)q.push(node->right);
            }
        }
        return root->val;

    }
};