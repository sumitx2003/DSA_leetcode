class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>vec(row,vector<int>(col,0));

        int x=0;
        int i=1;
        while(x<k){
            x=col*i-k;
            i++;

        }

        for(int i=0;i<row;i++){
            if(i%2==0){     // we will do  the left shift
                for(int j=0;j<col;j++){
                     int z=(j+x)%col;
                     vec[i][z]=mat[i][j];
                }
            }
            else{            // we wil do the right shift
                  for(int j=0;j<col;j++){
                    int y=(j+k)%col;
                    vec[i][y]=mat[i][j];
                  }
            }
        }
        if(mat==vec)return  true;

        return false;
    }
};