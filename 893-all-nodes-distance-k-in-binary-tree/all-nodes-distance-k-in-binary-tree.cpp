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
    unordered_map<TreeNode*,TreeNode*>par;
    vector<int>ans;

    void solve(TreeNode* root){
        if(!root)return;

        if(root->left){
            par[root->left]=root;
            solve(root->left);
        }
        if(root->right){
            par[root->right]=root;
            solve(root->right);
        }
    }
    void bfs(TreeNode* root,int k){
        queue<TreeNode*>q;
        q.push(root);
        unordered_set<TreeNode*>st;
        st.insert(root);

        int x=k;

        while(!q.empty()){
            int N=q.size();
            if(x==0){
                while(!q.empty()){
                    TreeNode* temp=q.front();
                    q.pop();
                    ans.push_back(temp->val);
                }
                break;
            }
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left  && st.find(node->left)==st.end()){
                    q.push(node->left);
                    st.insert(node->left);
                }

                if(node->right && st.find(node->right)==st.end()){
                    q.push(node->right);
                    st.insert(node->right);
                }

                if(par.find(node)!=par.end() && st.find(par[node])==st.end()){
                    q.push(par[node]);
                    st.insert(par[node]);
                }
            }
            x--;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)return ans;

        solve(root);
        bfs(target,k);
        
        return ans;

    }
};