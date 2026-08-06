class Solution {
public:
    int t[1001][1001];
    int solve(string &s,int low,int high){
        if(low>high)return 0;

        if(low==high)return 1;     // very important base case

        if(t[low][high]!=-1)return t[low][high];

        int take=0;
        int take1=solve(s,low+1,high);
        int take2=solve(s,low,high-1);

        if(s[low]==s[high]){
            take=2+solve(s,low+1,high-1);
        }
        return t[low][high]=max(take,max(take1,take2));
    }
    int longestPalindromeSubseq(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,s.length()-1);
    }
};