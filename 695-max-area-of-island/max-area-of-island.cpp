class Solution {
public:
    vector<vector<int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                  if(grid[i][j]==1){
                       grid[i][j]=0;
                       q.push({i,j});

                       while(!q.empty()){
                           int x=q.front().first;
                           int y=q.front().second;
                           count++;
                           q.pop();

                           for(auto &dir:directions){
                               int a=x+dir[0];
                               int b=y+dir[1];

                               if(a<0 || a>=m || b<0 || b>=n || grid[a][b]==0)continue;

                               grid[a][b]=0;
                               q.push({a,b});
                           }
                       }
                       
                  }
                  ans=max(ans,count);
            }
            
        }
        return ans;
    }
};