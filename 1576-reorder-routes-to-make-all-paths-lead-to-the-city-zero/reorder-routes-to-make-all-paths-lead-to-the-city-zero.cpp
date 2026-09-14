class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>mp;
        set<pair<int,int>>st;

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);

            st.insert({u,v});
            
        }
        int count=0;
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        vis[0]=1;
        
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
                        if(st.find({neigh,node})==st.end())count++;
                    }
                }
            }
        }
        return count;
    }
};