class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
             int u=edges[i][0];
             int v=edges[i][1];

             mp[u].push_back(v);
             mp[v].push_back(u);
        }
        long long res=0;
        long long processed=0;
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                continue;
              }
            else{
                vis[i]=1;
                queue<int>q;
                q.push(i);
                long long count=0;
                

                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    count++;
                    
                    for(int j=0;j<mp[node].size();j++){
                          int neigh=mp[node][j];
                          if(!vis[neigh]){
                               vis[neigh]=1;
                               q.push(neigh);
                          }
                    }
                }
                res+=processed*count;
                processed+=count;

              }
        }
        return res;
    }
};