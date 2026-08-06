class Solution {
public:
    int t[501][501];
    int solve(string &s,int low,int high){
        if(low>=high)return 0;

        if(t[low][high]!=-1)return t[low][high];

        int take=0;
        int take1=0;
        int take2=0;
         if(s[low]==s[high]){
            take=solve(s,low+1,high-1);
        }
        else {
             take1=1+solve(s,low+1,high);
             take2=1+solve(s,low,high-1);
        }
       
        return t[low][high]=(take+min(take1,take2));
    }
    int minInsertions(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,s.length()-1);
    }
};