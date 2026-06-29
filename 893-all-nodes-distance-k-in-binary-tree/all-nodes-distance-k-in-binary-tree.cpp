/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;
    void inorder(TreeNode* root){
        if(root==NULL)return ;

        if(root->left){
            mp[root->left]=root;
        }
        inorder(root->left);
        if(root->right){
            mp[root->right]=root;
        }
        inorder(root->right);
    }

    void BFS(TreeNode* target,int k,vector<int>&res){
            queue<TreeNode*>q;
            q.push(target);
            unordered_set<int>vis;
            vis.insert(target->val);

            while(!q.empty()){
                int N=q.size();
                if(k==0)break;
                while(N--){
                    TreeNode* node=q.front();
                    q.pop();

                    if(node->left && !vis.count(node->left->val)){
                        q.push(node->left);
                        vis.insert(node->left->val);
                    }
                    if(node->right && !vis.count(node->right->val)){
                        q.push(node->right);
                        vis.insert(node->right->val);
                    }
                    if(mp.count(node) && !vis.count(mp[node]->val)){
                        q.push(mp[node]);
                        vis.insert(mp[node]->val);
                    }
                }
                k--;
            }
            while(!q.empty()){
                TreeNode* temp=q.front();
                q.pop();
                res.push_back(temp->val);
            }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        inorder(root);

        BFS(target,k,res);

        return res;

    }
};