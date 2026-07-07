class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        if(r*c!=mat.size()*mat[0].size())return mat;
        vector<vector<int>>vec(r,vector<int>(c,0));
        vector<int>ans;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                ans.push_back(mat[i][j]);
            }
        }
        int k=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                vec[i][j]=ans[k];
                k++;
            }
        }
        return vec;
    }
};