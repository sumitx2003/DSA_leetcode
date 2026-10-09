class Solution {
public:
    vector<vector<int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
    void bfs(vector<vector<char>>& board,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        board[i][j]='#';

          while(!q.empty()){
                       int x=q.front().first;
                       int y=q.front().second;
                       q.pop();

                       for(auto &dir:directions){
                            int a=x+dir[0];
                            int b=y+dir[1];

                            if(a<0 || a>=board.size() || b<0 || b>=board[0].size() || board[a][b]=='#' || board[a][b]=='X'){
                                continue;
                            }

                            board[a][b]='#';
                            q.push({a,b});
                       }
                  }
    }
     void bfs1(vector<vector<char>>& board,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        board[i][j]='O';

          while(!q.empty()){
                       int x=q.front().first;
                       int y=q.front().second;
                       q.pop();

                       for(auto &dir:directions){
                            int a=x+dir[0];
                            int b=y+dir[1];

                            if(a<0 || a>=board.size() || b<0 || b>=board[0].size() || board[a][b]=='O' || board[a][b]=='X'){
                                continue;
                            }

                            board[a][b]='O';
                            q.push({a,b});
                       }
                  }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<int>r={0,m-1};
        vector<int>c={0,n-1};

        for(int i=0;i<r.size();i++){
              for(int j=0;j<n;j++){
                if(board[r[i]][j]=='O')bfs(board,r[i],j);
              }
        }   

        for(int j=0;j<c.size();j++){
              for(int i=0;i<m;i++){
                 if(board[i][c[j]]=='O')bfs(board,i,c[j]);
              }
        }

        queue<pair<int,int>>q;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(board[i][j]=='O'){
                     q.push({i,j});
                     board[i][j]='X';

                    while(!q.empty()){
                         int x=q.front().first;
                         int y=q.front().second;
                         q.pop();

                         for(auto &dir:directions){
                               int a=x+dir[0];
                               int b=y+dir[1];

                            if(a<1 || a>=m-1 || b<1 || b>=n-1 || board[a][b]=='X' || board[a][b]=='#')continue;

                               q.push({a,b});
                               board[a][b]='X';

                         }
                    }
                }
            }
        }

        for(int i=0;i<r.size();i++){
              for(int j=0;j<n;j++){
                if(board[r[i]][j]=='#')bfs1(board,r[i],j);
              }
        }   

        for(int j=0;j<c.size();j++){
              for(int i=0;i<m;i++){
                 if(board[i][c[j]]=='#')bfs1(board,i,c[j]);
              }
        }
        
    }
};