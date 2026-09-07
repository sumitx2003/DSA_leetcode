class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        vector<bool>vis(rooms.size(),0);

        q.push(0);
        vis[0]=1;

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int node=q.front();
                q.pop();

                for(int j=0;j<rooms[node].size();j++){
                     int neigh=rooms[node][j];
                     if(!vis[neigh]){
                        vis[neigh]=1;
                        q.push(neigh);
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