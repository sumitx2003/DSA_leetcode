class Solution {
public:
    int t[2501][2501];
    int solve(vector<int>&nums,int i,int prevIdx){
        if(i==nums.size()){
            return 0;
        }
        if(prevIdx!=-1 && t[i][prevIdx]!=-1)return t[i][prevIdx];

        int take=0;
        int skip=solve(nums,i+1,prevIdx);
        if(prevIdx==-1 || nums[i]>nums[prevIdx]){
            take=1+solve(nums,i+1,i);
        }
        if(prevIdx!=-1)t[i][prevIdx]=max(skip,take);

        return max(skip,take);

    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,-1);
    }
};