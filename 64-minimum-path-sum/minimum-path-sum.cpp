class Solution {
public:
    int t[201][201];
    int solve(vector<vector<int>>&grid,int i,int j){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }

        if(t[i][j]!=-1)return t[i][j];

        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())return INT_MAX;

        int down=solve(grid,i+1,j);
        int right=solve(grid,i,j+1);

        return t[i][j]=grid[i][j]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        return solve(grid,0,0);
    }
};