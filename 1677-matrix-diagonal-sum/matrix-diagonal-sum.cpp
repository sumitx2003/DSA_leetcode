class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int x=mat.size()-1;
        int y=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i==j){
                    sum+=mat[i][j];
                    if(i==y && x==j){
                        y++;
                        x--;
                    }
                    else{ 
                        sum+=mat[y][x];
                        y++;
                        x--;
                    }
                   
                }
            }
        }
        return sum;
    }
};