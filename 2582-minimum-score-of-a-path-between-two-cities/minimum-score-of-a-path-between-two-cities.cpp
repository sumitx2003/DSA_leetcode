class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // vector<vector<pair<int,int>>> adj(n + 1);
        // for (auto& road : roads) {
        //     int u = road[0];
        //     int v = road[1];
        //     int w = road[2];
        //     adj[u].push_back({v, w});
        //     adj[v].push_back({u, w});
        // }

        // vector<bool> vis(n + 1, false);
        // queue<int> q;
        // q.push(1);
        // vis[1] = true;

        // int minEdge = INT_MAX;

        // while (!q.empty()) {
        //     int node = q.front();
        //     q.pop();

        //     for (int j=0;j<adj[node].size();j++) {
        //         int neigh=adj[node][j].first;
        //         int weight=adj[node][j].second;
        //         minEdge = min(minEdge, weight);
        //         if (!vis[neigh]) {
        //             vis[neigh] = true;
        //             q.push(neigh);
        //         }
        //     }
        // }

        // return minEdge;

        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int dis=roads[i][2];
            mp[u].push_back({v,dis});
            mp[v].push_back({u,dis});
        }
        vector<bool>vis(n+1,0);
        queue<int>q;
        q.push(1);
        int  mindis=INT_MAX;
        vis[1]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<mp[node].size();i++){
                  int neigh=mp[node][i].first;
                  int dist=mp[node][i].second;
                  mindis=min(mindis,dist);
                  if(!vis[neigh]){
                    vis[neigh]=1;
                    q.push(neigh);
                  }
            }
        }
        return  mindis;
    }
};
