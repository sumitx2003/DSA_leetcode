class Solution {
public:
    unordered_map<int,vector<int>>mp;
    vector<vector<int>>ans;
    int n=0;
    void solve(int node,vector<int>&vec,vector<vector<int>>& graph){
        vec.push_back(node);
         if(node==n-1){
            ans.push_back(vec);
         }
         
         
         for(int i=0;i<graph[node].size();i++){
               int neigh=graph[node][i];
               solve(neigh,vec,graph);
         }
         vec.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int>vec;
        solve(0,vec,graph);
        return ans;
    }
};