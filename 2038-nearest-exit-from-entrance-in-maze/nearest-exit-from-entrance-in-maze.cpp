class Solution {
public:
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();

        queue<pair<int,int>>q;
        int count=0;

        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                if((x==0 || y==0 || x==m-1 || y==n-1) && count>0)return count++;

                for(auto &dir:directions){
                    int i=x+dir[0];
                    int j=y+dir[1];

                    if(i<0 || i>=m || j<0 || j>=n)continue;

                    if(maze[i][j]=='.'){
                        q.push({i,j});
                        maze[i][j]='+';
                    }
                }
            }
            count++;
        }
        return -1;
    }
};