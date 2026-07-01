class Solution {
public:
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 ||  grid[n-1][n-1]==1)return 0;
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    pq.push({0,i,j});
                    dis[i][j]=0;
                    while(!pq.empty()){
                        auto[dist,i,j]=pq.top();
                        pq.pop();
                        for(auto &dir:directions){
                            int ni=dir[0]+i;
                            int nj=dir[1]+j;

                            if((ni<0 || ni>=n) || (nj<0 || nj>=n) || grid[ni][nj]==1)continue;

                            if(dis[ni][nj]>dis[i][j]+1){
                                dis[ni][nj]=dis[i][j]+1;
                                pq.push({dis[ni][nj],ni,nj});
                            }
                        }
                    }
                }

            }
        }
        // dis with the maximum safeness ,now we have to move from here with
        priority_queue<tuple<int,int,int>>q;
        vector<vector<int>>ans(n,vector<int>(n,INT_MAX));
        q.push({dis[0][0],0,0});
        ans[0][0]=dis[0][0];
        while(!q.empty()){
            auto[dist,i,j]=q.top();
            q.pop();
            if(i==n-1 && j==n-1)return dist;

            for(auto &dir:directions){
                int ni=i+dir[0];
                int nj=j+dir[1];

                if((ni<0 || ni>=n) || (nj<0 || nj>=n))continue;

                if(ans[ni][nj]>ans[i][j]){
                    ans[ni][nj]=min(ans[i][j],dis[ni][nj]);
                    q.push({ans[ni][nj],ni,nj});
                }
            }
        }
        return 0;

    }
};