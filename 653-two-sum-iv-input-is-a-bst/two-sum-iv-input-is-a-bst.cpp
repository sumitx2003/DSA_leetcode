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
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;

        if(root->left==NULL && root->right==NULL)return false;

        unordered_map<int,TreeNode*>mp;
        queue<TreeNode*>q;
        q.push(root);


        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();

               mp[k-node->val]=node;

                if(node->left)q.push(node->left);

                if(node->right)q.push(node->right);
            }
        }
        q.push(root);
        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(mp.find(node->val)!=mp.end() && node!=mp[node->val])return true;

                if(node->left)q.push(node->left);

                if(node->right)q.push(node->right);

            }
        }
        return false;
    }
};