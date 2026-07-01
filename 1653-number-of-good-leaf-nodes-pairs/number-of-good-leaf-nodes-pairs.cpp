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
    unordered_map<TreeNode*,TreeNode*>mp;
    int count=0;
    void bfs(TreeNode* node,int distance,unordered_set<TreeNode*>&st){
        int level=0;
        queue<TreeNode*>q;
        q.push(node);
        st.insert(node);
        while(!q.empty() && level<=distance){
            int N=q.size();
            while(N--){
                TreeNode* temp=q.front();
                q.pop();
                if(level>distance)break;

                if(temp->left==NULL && temp->right==NULL){
                    if(node!=temp && level<=distance){
                          count++;
                    }

                }

                if(temp->left && st.find(temp->left)==st.end()){
                    q.push(temp->left);
                    st.insert(temp->left);
                }

                if(temp->right && st.find(temp->right)==st.end()){
                    q.push(temp->right);
                    st.insert(temp->right);
                }

                if(mp[temp]!=NULL && st.find(mp[temp])==st.end()){
                    st.insert(mp[temp]);
                    q.push(mp[temp]);
                }
            }
            level++;
        }
        
    }
    int countPairs(TreeNode* root, int distance) {
        vector<TreeNode*>vec;
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left==NULL && node->right==NULL)vec.push_back(node);

                if(node->left){
                    q.push(node->left);
                    mp[node->left]=node;
                }

                if(node->right){
                    q.push(node->right);
                    mp[node->right]=node;
                }

            }
        }
       unordered_set<TreeNode*>st;
        for(int i=0;i<vec.size();i++){
             bfs(vec[i],distance,st);
             st.clear();
        }
        return count/2;
    }
};