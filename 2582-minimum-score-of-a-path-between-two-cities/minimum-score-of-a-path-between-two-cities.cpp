class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int mini=INT_MAX;
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            mp[u].push_back({v,wt});
            mp[v].push_back({u,wt});
        }
        queue<int>q;
        vector<int>vis(n+1,0);
        vis[1]=1;
        q.push(1);
        while(!q.empty()){
                int node=q.front();
                q.pop();

                for(int j=0;j<mp[node].size();j++){
                     int neigh=mp[node][j].first;
                     int w=mp[node][j].second;
                     mini=min(mini,w);
                     if(!vis[neigh]){
                         q.push(neigh);
                         
                         vis[neigh]=1;
                     }
                }
                
        }
        return mini;
    }
};