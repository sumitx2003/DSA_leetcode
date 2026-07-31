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
    unordered_map<TreeNode*,TreeNode*>par;
    TreeNode* strt=NULL;
    void solve(TreeNode* root,int start){
        if(!root)return;

        if(root->val==start)strt=root;

        if(root->left){
            par[root->left]=root;
            solve(root->left,start);
        }
        if(root->right){
            par[root->right]=root;;
            solve(root->right,start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root)return 0;

        solve(root,start);

        queue<TreeNode*>q;
        unordered_set<TreeNode*>st;
        int time=0;
        st.insert(strt);
        q.push(strt);

        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && st.find(node->left)==st.end()){
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
            time++;
        }
        return time-1;
        
    }
};