class Solution {
public:
    void solve(unordered_map<int,vector<int>>&mp,int curr,int parent,string &labels,vector<int>&res,vector<int>&count){
         char mylabel=labels[curr];

         int before=count[mylabel-'a'];

         count[mylabel-'a']+=1;

         for(int i=0;i<mp[curr].size();i++){
              int neigh=mp[curr][i];

              if(neigh==parent)continue;

              solve(mp,neigh,curr,labels,res,count);
         }
         int after=count[mylabel-'a'];
         res[curr]=after-before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

         vector<int>res(n,0);
         vector<int>count(26,0);
         solve(mp,0,-1,labels,res,count);

         return res;
    }
};