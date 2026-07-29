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
        vector<vector<int>>ans;
        if(!root)return ans;
        unordered_map<int,vector<pair<int,int>>>mp;
        set<int>st;

        queue<tuple<TreeNode*,int,int>>q;
        int row=0;
        int col=0;
        q.push({root,row,col});
        
        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node = get<0>(q.front());
                int column = get<2>(q.front());
                int row = get<1>(q.front());
                q.pop();

                mp[column].push_back({row,node->val});
                st.insert(column);

                if(node->left){
                    q.push({node->left,row+1,column-1});
                }
                if(node->right){
                    q.push({node->right,row+1,column+1});
                }
            }
        }
    
        for(auto &it:st){
            vector<pair<int,int>>vec=mp[it];
            sort(vec.begin(),vec.end());
            vector<int>a;
            for(int j=0;j<vec.size();j++){
                int u=vec[j].second;
                a.push_back(u);
            }
            ans.push_back(a);
        }
        return ans;
    }
};