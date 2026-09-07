class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            mp[u].push_back(v);
            mp[v].push_back(u);

        }
        queue<int>q;
        vector<bool>vis(n,0);
        q.push(source);
        vis[source]=1;

        while(!q.empty()){
            int N=q.size();
            while(!q.empty()){
                int node=q.front();
                q.pop();

                if(node==destination)return true;

                for(int j=0;j<mp[node].size();j++){
                    int neigh=mp[node][j];

                    if(!vis[neigh]){
                        vis[neigh]=1;
                        q.push(neigh);
                    }
                }
            }
        }
        return false;
    }
};