class Solution {
public:
    int t[46];
    int solve(int n){
        if(n==0)return 1;

        if(t[n]!=-1)return t[n];

        int onestep=0;
        int twostep=0;
        if(n>0){
             onestep=solve(n-1);
        }
        
        if(n>1){
             twostep=solve(n-2);
        }
        

        return t[n]=onestep+twostep;
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};