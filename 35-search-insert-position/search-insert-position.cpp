class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int si=0;
        int ei=nums.size()-1;
        int idx=-1;
        
        while(si<=ei){
            int mid=(si+ei)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                si=mid+1;
            }
            else{
                ei=mid-1;
            }
            idx=mid;
        }
        if(nums[idx]>target)return idx;
        
        return idx+1;
    }
};