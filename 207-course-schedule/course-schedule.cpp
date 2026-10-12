class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>>mp;
        vector<int>indeg(n,0);
        
        for(int i=0;i<prerequisites.size();i++){
              int u=prerequisites[i][0];
              int v=prerequisites[i][1];

              mp[v].push_back(u);
              indeg[u]++;
        }
        vector<int>vis(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
             if(indeg[i]==0 && !vis[i]){
                  vis[i]=1;
                  q.push(i);

                  while(!q.empty()){
                        int node=q.front();
                        q.pop();

                        for(int j=0;j<mp[node].size();j++){
                               int neigh=mp[node][j];
                               indeg[neigh]--;

                               if(!vis[neigh] && indeg[neigh]==0){
                                    vis[neigh]=1;
                                    q.push(neigh);
                               }
                        }
                  }
             }
        }
        for(int i=0;i<vis.size();i++){
              if(vis[i]==0)return false;
        }
        return true;

    }
};