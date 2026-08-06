class Solution {
public:
    int dp[1001][1001];
    int solve(string &s,string &t,int i,int j){
        if(i>=s.length()){
            if(j>=t.length())return 1;

            return 0;
        }

        if(dp[i][j]!=-1)return dp[i][j];
        
        int take=0;
        if(s[i]==t[j]){
            take=solve(s,t,i+1,j+1);
        }

        int skip=solve(s,t,i+1,j);

        return dp[i][j]=(skip+take);
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};