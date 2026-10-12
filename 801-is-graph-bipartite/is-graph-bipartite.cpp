class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){

            if(!vis[i] && color[i]==-1){
                  
            color[i]=0;
            vis[i]=1;
            q.push(i);

        while(!q.empty()){
              int node=q.front();
              q.pop();
              
              for(int j=0;j<graph[node].size();j++){
                    int neigh=graph[node][j];

                    if(color[node]==color[neigh])return false;

                    if(!vis[neigh]){
                         vis[neigh]=1;
                         color[neigh]=(1+color[node])%2;
                         q.push(neigh);
                    }
              }
        }
    }
          
        }
        return true;
        
    }
};