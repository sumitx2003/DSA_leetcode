class Solution {
public:
    int t[30001][2];
    int solve(vector<int>&prices,int i,bool flag){
        if(i>=prices.size()){
            if(flag==true)return 0;

            return 0;
        }
        if(t[i][flag]!=-1)return t[i][flag];

        int buy=0;
        int skip=0;
        int sell=0;
        skip=solve(prices,i+1,flag);
        if(flag==true){
            buy=(-prices[i])+solve(prices,i+1,!flag); 
        }
        else if(flag==false){
            sell=prices[i]+solve(prices,i+1,!flag);
        }
        return t[i][flag]=max(skip,max(buy,sell));
    }
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(prices,0,true);
    }
};