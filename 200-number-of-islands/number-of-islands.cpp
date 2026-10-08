class Solution {
public:
    vector<vector<int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<grid.size();i++){
             for(int j=0;j<grid[0].size();j++){
                   if(grid[i][j]=='1'){
                       count++;
                       grid[i][j]='0';
                       q.push({i,j});

                       while(!q.empty()){
                            int x=q.front().first;
                            int y=q.front().second;
                            q.pop();

                            for(auto &dir:directions){
                                  int a=x+dir[0];
                                  int b=y+dir[1];

                                  if(a<0 || a>=m || b>=n || b<0 || grid[a][b]=='0' ){
                                    continue;
                                  }

                                      grid[a][b]='0';
                                      q.push({a,b});
                            }
                       }
                   }
             }
        }
        return count;
    }
};