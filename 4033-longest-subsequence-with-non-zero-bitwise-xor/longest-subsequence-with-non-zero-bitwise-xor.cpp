class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int count=0;
        int xr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)count++;
            xr=xr^nums[i];
        }
        int n=nums.size();
        if(count==n)return 0;
        if(xr==0){
            return n-1;
        }
        
        return n;
    }
};