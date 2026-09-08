class Solution {
public:
    unordered_map<int,vector<int>>mp;
    string label="";
   void solve(int curr,int parent,vector<int>&count,vector<int>&res){
        char ch=label[curr];
        int before=count[ch-'a'];
        count[ch-'a']+=1;
        for(int i=0;i<mp[curr].size();i++){
            int neigh=mp[curr][i];
            if(neigh==parent)continue;
            solve(neigh,curr,count,res);
        }
        int after=count[ch-'a'];
        res[curr]=after-before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        for(int i=0;i<edges.size();i++){
              int u=edges[i][0];
              int v=edges[i][1];

              mp[u].push_back(v);
              mp[v].push_back(u);
        }
        label=labels;
        vector<int>res(n,0);
        vector<int>count(26,0);

        solve(0,-1,count,res);
        return res;
    }
};