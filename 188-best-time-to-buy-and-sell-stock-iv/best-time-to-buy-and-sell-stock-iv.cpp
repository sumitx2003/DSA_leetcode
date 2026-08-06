class Solution {
public:
    int K;
    int t[1001][101][2];
    int solve(vector<int>&prices,int i,int count,bool flag){
        if(i>=prices.size()){
            if(flag==true && count<=K){
                return 0;
            }
            return 0;
        }
        if(t[i][count][flag]!=-1)return t[i][count][flag];

        int buy=0;
        int sell=0;
        int skip=solve(prices,i+1,count,flag);
        if(flag==true && count<K){
            buy=(-prices[i])+solve(prices,i+1,count,!flag);
        }
        else if(flag==false && count<K){
            sell=prices[i]+solve(prices,i+1,count+1,!flag);
        }
        return t[i][count][flag]=max(skip,max(buy,sell));
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(t,-1,sizeof(t));
        K=k;
        return solve(prices,0,0,true);
    }
};