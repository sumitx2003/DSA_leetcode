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
    int bfs(TreeNode* node){
        int avg=0;
        int c=0;
        queue<TreeNode*>q;
        q.push(node);
        
        while(!q.empty()){
            int N=q.size();;
            while(N--){
                TreeNode* node=q.front();
                q.pop();
                avg+=node->val;
                c++;

                if(node->left)q.push(node->left);

                if(node->right)q.push(node->right);

            }
        }
        return avg/c;
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int N=q.size();;
            while(N--){
                TreeNode* node=q.front();
                q.pop();
                
                int x=bfs(node);
                if(x==node->val)count++;

                if(node->left)q.push(node->left);

                if(node->right)q.push(node->right);

            }
        }
        return count;
    }
};