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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<pair<int,int>>>mp;
        unordered_map<TreeNode*,int>mp1;
        queue<TreeNode*>q;
        q.push(root);
        
        mp[0].push_back({0,root->val});
        mp1[root]=0;
        int level=0;


        while(!q.empty()){
            int N=q.size();
            level++;
            while(N--){
                TreeNode* node=q.front();
                q.pop();
                int x=mp1[node];

                if(node->left){
                    q.push(node->left);
                    mp1[node->left]=x-1;
                    mp[x-1].push_back({level,node->left->val});
                }
                if(node->right){
                    q.push(node->right);
                    mp1[node->right]=x+1;
                    mp[x+1].push_back({level,node->right->val});
                }
            }
        }
        // now we will solve the mp into the min to max
        set<int>st;
        for(auto &it:mp){
            st.insert(it.first);
        }

        vector<vector<int>>ans;
        for(auto &it:st){
            vector<pair<int,int>>v=mp[it];
            sort(v.begin(),v.end());
            vector<int>vec;
            for(int i=0;i<v.size();i++){
                int x=v[i].second;
                vec.push_back(x);
            }
            ans.push_back(vec);
        }
        return ans;

    }
};