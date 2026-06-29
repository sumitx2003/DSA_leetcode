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
    int amountOfTime(TreeNode* root, int start) {
        // first we have connvrt this into the graph or we can make the map for the parent
        unordered_map<TreeNode*,TreeNode*>mp;
        set<TreeNode*>st;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* strt;

        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();
                if(node->val==start)strt=node;

                if(node->left){
                    mp[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    mp[node->right]=node;
                    q.push(node->right);
                }
            }
        }
        q.push(strt);
        st.insert(strt);
        int count=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();
                
                if( node->left && st.find(node->left)==st.end()){
                    st.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && st.find(node->right)==st.end()){
                    st.insert(node->right);
                    q.push(node->right);
                }
                if(mp.find(node)!=mp.end() && st.find(mp[node])==st.end()){
                    st.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
            count++;
        }
        return count-1;
          
    }
};