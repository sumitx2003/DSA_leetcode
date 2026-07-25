class Solution {
public:
    int t[10001];
    int MOD=1e9+7;
    int solve(int idx,int n){
        if(idx>=n)return 1;

        if(t[idx]!=-1)return t[idx];

        int skip=solve(idx+1,n);

        int steal=solve(idx+2,n);

        return t[idx]=(skip+steal)%MOD;
    }
    int countHousePlacements(int n) {
        memset(t,-1,sizeof(t));
         long long ways= (solve(0,n))%MOD;
        return (ways*ways)%MOD;
    }
};