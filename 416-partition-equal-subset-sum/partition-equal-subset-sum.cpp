class Solution {
public:
    int t[201][20001];
    bool solve(vector<int>&nums,int idx,int amount){
        if(amount==0)return true;
             
        if(idx>=nums.size() || amount<0)return false;

        if(t[idx][amount]!=-1)return t[idx][amount];

        bool take=solve(nums,idx+1,amount-nums[idx]);
        bool skip=solve(nums,idx+1,amount);

        return t[idx][amount]=(take || skip);
    }
    bool canPartition(vector<int>& nums) {
        int x=0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<nums.size();i++){
            x+=nums[i];
        }
        if(x%2!=0)return false;

        x=x/2;
        return solve(nums,0,x);
    }
};