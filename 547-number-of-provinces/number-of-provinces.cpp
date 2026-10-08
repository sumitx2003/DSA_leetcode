class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<isConnected.size();i++){
             int u=i+1;
             for(int j=0;j<isConnected[i].size();j++){
                  int v=j+1;
                  if(u==v || isConnected[i][j]==0){
                      continue;
                  }
                  else{
                       mp[u].push_back(v);
                       mp[v].push_back(u);
                  }
             }
        }
        int n=isConnected.size();
        vector<bool>vis(n+1,0);
        int count=0;
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                 vis[i]=1;
                 q.push(i);
                 count++;

                 while(!q.empty()){
                      int node=q.front();
                      q.pop();
                      
                      for(int j=0;j<mp[node].size();j++){
                          int neigh=mp[node][j];
                          if(!vis[neigh]){
                             vis[neigh]=1;
                             q.push(neigh);
                          }
                      }
                 }
            }
        }
        return count;
    }
};