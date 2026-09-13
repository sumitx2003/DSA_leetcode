class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<flights.size();i++){
             int u=flights[i][0];
             int v=flights[i][1];
             int w=flights[i][2];
             mp[u].push_back({v,w});
        }
        vector<int>dist(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src]=0;
        int level=0;
        while(!q.empty()){
            int N=q.size();
            if(level>=k+1){
                break;
            }
            while(N--){
                int node=q.front().first;
                int wt=q.front().second;
                q.pop();

                for(int j=0;j<mp[node].size();j++){
                     int neigh=mp[node][j].first;
                     int w=mp[node][j].second;
                     if(dist[neigh]>wt+w){
                          dist[neigh]=wt+w;
                          q.push({neigh,dist[neigh]});
                     }
                }
            }
            level++;
        }
        if(dist[dst]!=INT_MAX)return dist[dst];

        return -1;
    }
};