class Solution {
public:
    int t[21][2001];
    int solve(vector<int>&nums,int i,int sum,int tgt){
        if(i>=nums.size()){
            if(sum==tgt){
                return 1;
            }else{
                return 0;
            }
        }

        if(t[i][sum+1000]!=-1)return t[i][sum+1000];

        int add=solve(nums,i+1,sum+nums[i],tgt);
        int sub=solve(nums,i+1,sum-nums[i],tgt);

        return t[i][sum+1000]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,0,target);
    }
};