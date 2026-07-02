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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>vec;
        vec.push_back(0);
        unordered_map<TreeNode*,int>mp;
        

        while(!q.empty()){
            int N=q.size();
            int sum=0;
            while(N--){
                TreeNode* node=q.front();
                q.pop();


                if(node->left){
                    sum+=node->left->val;
                    mp[node]+=node->left->val;
                    q.push(node->left);
                }
                if(node->right){
                    sum+=node->right->val;
                    mp[node]+=node->right->val;
                    q.push(node->right);
                }
                
            }
            vec.push_back(sum);
        }
        q.push(root);
        int level=0;
        root->val=0;
        while(!q.empty()){
            int N=q.size();
            level++;
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    node->left->val=vec[level]-mp[node];
                }
                if(node->right){
                    q.push(node->right);
                    node->right->val=vec[level]-mp[node];
                }
            }
        }
        return root;
    }
};