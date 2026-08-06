class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int cost=prices[0];
        for(int i=0;i<prices.size();i++){
            int x=prices[i]-cost;
            profit=max(profit,x);
            cost=min(cost,prices[i]);
        }
        return profit;
    }
};