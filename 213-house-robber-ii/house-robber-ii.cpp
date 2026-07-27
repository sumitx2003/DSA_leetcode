class Solution {
public:
    int t[101];
    int t1[101];
    int solve(vector<int>&nums,int idx){
          if(idx>=nums.size()-1)return 0;

          if(t[idx]!=-1)return t[idx];

          int take=nums[idx]+solve(nums,idx+2);
          int skip=solve(nums,idx+1);       
            
          return t[idx]=max(skip,take);
    }
    int solve1(vector<int>&nums,int idx){
        if(idx>=nums.size())return 0;

        if(t1[idx]!=-1)return t1[idx];

        int take=nums[idx]+solve1(nums,idx+2);
        int skip=solve1(nums,idx+1);

        return t1[idx]=max(skip,take);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        memset(t1,-1,sizeof(t1));
        if(nums.size()==1)return nums[0];

        if(nums.size()==2)return max(nums[0],nums[1]);

        int x= solve(nums,0);
        int y=solve1(nums,1);   

        return max(x,y);
    }
};