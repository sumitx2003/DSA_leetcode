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
    int maxs=INT_MIN;
    TreeNode* s;
    void dfs(TreeNode* node){
        if(node==NULL)return;

        if(abs((node->val)-(s->val))>maxs){
            maxs=abs((node->val)-(s->val));
        }

        dfs(node->left);
        dfs(node->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)return 0;
        
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();
                s=node;
                dfs(node);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return maxs;
    }
};