class Solution {
public:
    vector<vector<int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(board[i][j]=='X'){
                      q.push({i,j});
                      count++;
                      
                      while(!q.empty()){
                           int x=q.front().first;
                           int y=q.front().second;
                           q.pop();

                           for(auto &dir:directions){
                               int a=x+dir[0];
                               int b=y+dir[1];

                               if(a<0 || a>=m || b<0 || b>=n || board[a][b]=='.')continue;

                                 board[a][b]='.';
                                 q.push({a,b});
                           }
                      }
                 }
             }
        }
        return count;
    }
};