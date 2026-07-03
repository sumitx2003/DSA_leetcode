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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        int level=0;
        q.push(root);

        while(!q.empty()){
            int N=q.size();
            level++;
            vector<int>vec;
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    vec.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    vec.push_back(node->right->val);
                }

            }
            if(level%2==1){
                reverse(vec.begin(),vec.end());

                queue<TreeNode*>q1=q;
                int i=0;

                while(!q1.empty()){
                    TreeNode* node=q1.front();
                    q1.pop();

                    node->val=vec[i];
                    i++;
                }
            }
            
        }
        return root;
    }
};