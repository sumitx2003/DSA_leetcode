class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>vis(n,0);
        unordered_map<int,vector<int>>mp;
        vector<int>indeg(n,0);

        for(int i=0;i<prerequisites.size();i++){
              int u=prerequisites[i][0];
              int v=prerequisites[i][1];
              
              mp[v].push_back(u);
              indeg[u]++;
        }
        vector<int>res;
        queue<int>q;

        for(int i=0;i<indeg.size();i++){
               if(indeg[i]==0 && !vis[i]){
                    q.push(i);
                    vis[i]=1;

                    while(!q.empty()){
                          int node=q.front();
                          q.pop();

                          res.push_back(node);

                          for(int j=0;j<mp[node].size();j++){
                                 int neigh=mp[node][j];
                                 indeg[neigh]--;

                                 if(indeg[neigh]==0 && !vis[neigh]){
                                      q.push(neigh);
                                      vis[neigh]=1;
                                 }
                          }
                    }
               }
        }
        for(int i=0;i<vis.size();i++){
              if(!vis[i])return {};
        }
        return res;
    
    }
};