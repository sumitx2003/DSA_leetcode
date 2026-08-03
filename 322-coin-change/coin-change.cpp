class Solution {
public:
    int t[10001];
    int solve(vector<int>&coins,int amount){
        if(amount==0)return 0;

        if(amount<0)return 1e9;

        if(t[amount]!=-1)return t[amount];

        int ans=1e9;
        for(int i=0;i<coins.size();i++){
            int take=1+solve(coins,amount-coins[i]);
            ans=min(ans,take);
        }
        return t[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        int x= solve(coins,amount);
        if(x!=1e9)return x;

        return -1;
    }
};