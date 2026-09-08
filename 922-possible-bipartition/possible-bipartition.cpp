class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<dislikes.size();i++){
             int u=dislikes[i][0];
             int v=dislikes[i][1];

             mp[u].push_back(v);
             mp[v].push_back(u);

        }

        vector<bool>vis(n+1,0);
        vector<int>color(n+1,-1);
        queue<int>q;
        
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
             q.push(i);
            vis[i]=1;
           color[i]=0;

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int node=q.front();
                q.pop();

                for(int j=0;j<mp[node].size();j++){
                    int neigh=mp[node][j];

                    if(!vis[neigh]){
                        vis[neigh]=1;
                        q.push(neigh);
                        color[neigh]=(1+color[node])%2;
                    }
                    else if(vis[neigh] && color[node]==color[neigh])return false;
                }
            }
        }
    }
       
        return true;

    }
};