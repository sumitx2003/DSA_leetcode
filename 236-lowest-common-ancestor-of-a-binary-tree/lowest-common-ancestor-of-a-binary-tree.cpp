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
    
    void solve(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&par,vector<TreeNode*>&ans){
        if(!root)return;

        if(par.find(root)!=par.end() && par[root]!=NULL){
            ans.push_back(par[root]);
        }
        solve(par[root],par,ans);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q)return root;
        
        unordered_map<TreeNode*,TreeNode*>par;
        queue<TreeNode*>pq;
        if(!root)return NULL;
        par[root]=NULL;

        pq.push(root);

        while(!pq.empty()){
            int N=pq.size();
            while(N--){
                TreeNode* node=pq.front();
                pq.pop();

                if(node->left){
                    pq.push(node->left);
                    par[node->left]=node;
                }
                if(node->right){
                    pq.push(node->right);
                    par[node->right]=node;
                }
            }
        }
        unordered_set<TreeNode*>st1;
        vector<TreeNode*>first;
        vector<TreeNode*>second;
    
        solve(p,par,first);
        solve(q,par,second);

        reverse(first.begin(),first.end());
        reverse(second.begin(),second.end());
        first.push_back(p);
        second.push_back(q);
        reverse(first.begin(),first.end());
        reverse(second.begin(),second.end());

        for(int i=0;i<first.size();i++){
            st1.insert(first[i]);
        }
        for(int i=0;i<second.size();i++){
            if(st1.find(second[i])!=st1.end())return second[i];
        }

        return  root;
    }
};