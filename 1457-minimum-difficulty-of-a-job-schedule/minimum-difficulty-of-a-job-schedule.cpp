class Solution {
public:
    // int t[301][11];
    // int solve(vector<int>& jobDifficulty,int n,int idx,int d){
    //     if(d==1){
    //         int maxD=jobDifficulty[idx];

    //         for(int i=idx;i<n;i++){
    //             maxD=max(maxD,jobDifficulty[i]);
    //         }
    //         return maxD;
    //     }
    //     if(t[idx][d]!=-1)return t[idx][d];

    //     int maxD=jobDifficulty[idx];
    //     int finalResult=INT_MAX;

    //     for(int i=idx;i<=n-d;i++){
    //         maxD=max(maxD,jobDifficulty[i]);
    //         int result=maxD+solve(jobDifficulty,n,i+1,d-1);

    //         finalResult=min(finalResult,result);
    //     }
    //     return t[idx][d]=finalResult;
    // }
    int t[301][11];
    int solve(vector<int>& jobDifficulty,int n,int idx,int d){
          if(d==1){
              int maxd=jobDifficulty[idx];
              for(int i=idx;i<jobDifficulty.size();i++){
                  maxd=max(maxd,jobDifficulty[i]);
              }
              return maxd;
          }
          if(t[idx][d]!=-1)return t[idx][d];

          int finalresult=INT_MAX;
          int maxd=jobDifficulty[idx];

          for(int i=idx;i<=jobDifficulty.size()-d;i++){
                maxd=max(maxd,jobDifficulty[i]);
                int res=maxd+solve(jobDifficulty,n,i+1,d-1);
                finalresult=min(finalresult,res);
          }

          return t[idx][d]=finalresult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
          if(n<d)return -1;
          memset(t,-1,sizeof(t));

          return solve(jobDifficulty,n,0,d);
        // int n=jobDifficulty.size();
        // // memset(t,-1,sizeof(t));
        // if(n<d){
        //     return -1;
        // }
        // // return solve(jobDifficulty,n,0,d);

        // int maxs=INT_MIN;
        // int sum=0;
        // if(d==1){
        //     for(int i=0;i<jobDifficulty.size();i++){
        //           maxs=max(maxs,jobDifficulty[i]);
        //     }
        //     return maxs;
        // }
        
        // else{
        //     for(int i=0;i<n-d+1;i++){
        //         maxs=max(maxs,jobDifficulty[i]);
        //     }  sum+=maxs;
        //     for(int i=n-d+1;i<n;i++){
        //         sum+=jobDifficulty[i];
        //     }
        // }
        // return sum;
    }
};