class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indeg(n,0);
        unordered_map<int,vector<int>>mp;
        vector<int>res;
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            indeg[v]++;
            mp[u].push_back(v);
        }
        for(int i=0;i<indeg.size();i++){
              if(indeg[i]!=0)continue;

              queue<int>q;
              vector<bool>vis(n,0);
              q.push(i);
              vis[i]=1;

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
                             }
                       }
                   }
              }
             res.push_back(i);
            //  int count=0;
            //  for(int k=0;k<vis.size();k++){
            //       if(vis[i]!=0)count++;

            //  }
            //  if(count==n)break;
        }
        return res;
    }
};