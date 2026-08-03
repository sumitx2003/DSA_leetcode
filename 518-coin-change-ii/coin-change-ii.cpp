class Solution {
public:
    int t[301][5001];
    int solve(vector<int>&coins,int i,int amount){
        if(amount==0)return 1;

        if(amount<0 || i>=coins.size())return 0;

        if(t[i][amount]!=-1)return t[i][amount];

        int take=0;
        if(amount>=coins[i]){
            take=solve(coins,i,amount-coins[i]);
        }
        int skip=solve(coins,i+1,amount);

        return t[i][amount]=(take+skip);  
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve(coins,0,amount);
    }
};