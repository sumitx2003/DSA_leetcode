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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                pq.push(node->val);

                if(node->left)q.push(node->left);

                if(node->right)q.push(node->right);

            }
        }
        int x=0;
        while(k){
            x=pq.top();
            pq.pop();
            k--;
        }
        return x;
    }
};