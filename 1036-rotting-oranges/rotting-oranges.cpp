class Solution {
public:
    vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        bool has=false;
        if(q.size()==0)has=true;
        
        int count=-1;
        while(!q.empty()){
             int N=q.size();
             while(N--){
                  int x=q.front().first;
                  int y=q.front().second;
                  q.pop();

                  for(auto &dir:directions){
                       int a=x+dir[0];
                       int b=y+dir[1];

                       if(a<0 || a>=m || b<0 || b>=n || grid[a][b]==0 || grid[a][b]==2)continue;

                       q.push({a,b});
                       grid[a][b]=2;
                  }
             }
             count++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(grid[i][j]==1)return -1;
            }
        }
        if(has==true)return 0;
        
        return count;
    }
};