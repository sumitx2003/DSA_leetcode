class Solution {
public:
    int findMin(vector<int>& nums) {
        int si=0;
        int ei=nums.size()-1;
         int ans=nums[(si+ei)/2];
        while(si<=ei){
            int mid=si+(ei-si)/2;
            ans=min(nums[mid],ans);
            if(nums[mid]>nums[si] && nums[mid]<nums[ei]){
                ei=mid-1;

            }
            else if(nums[mid]<nums[ei]){
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        return ans;
    }
};