class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int sum=0;
    int total=0;
    void solve(int curr,int parent,int level,vector<int>&count){
         count[curr]+=1;
         sum+=level;
         total+=1;
          for(int i=0;i<mp[curr].size();i++){
             int neigh=mp[curr][i];

             if(neigh==parent)continue;
             solve(neigh,curr,level+1,count);
          }
          if(parent!=-1){
            count[parent]+=count[curr];
          }
          
    }
    void dfs(int curr,int parent,vector<int>&count,vector<int>&ans){
           for(int i=0;i<mp[curr].size();i++){
               int neigh=mp[curr][i];

               if(neigh==parent)continue;
               
               ans[neigh]=ans[curr]-count[neigh]+total-count[neigh];
               dfs(neigh,curr,count,ans);
           }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
         vector<int>ans(n,0);
         vector<int>count(n,0);
         int level=0;
         solve(0,-1,0,count);
         ans[0]=sum;
         dfs(0,-1,count,ans);

        return ans;
        
    }
};