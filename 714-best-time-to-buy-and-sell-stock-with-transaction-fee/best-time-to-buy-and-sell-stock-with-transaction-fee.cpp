class Solution {
public:
    int t[50001][2];
    int solve(vector<int>&prices,int i,int fee,bool flag){
        if(i>=prices.size()){
            if(flag==true)return 0;

            return 0;
        }
        if(t[i][flag]!=-1)return t[i][flag];
        int buy=0;
        int sell=0;
        int skip=solve(prices,i+1,fee,flag);

        if(flag==true){
            buy=(-prices[i])+solve(prices,i+1,fee,!flag);
        }
        else if(flag==false){
            sell=(prices[i]-fee)+solve(prices,i+1,fee,!flag);
        }
        return t[i][flag]=max(skip,max(sell,buy));
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(t,-1,sizeof(t));
        return solve(prices,0,fee,true);
    }
};