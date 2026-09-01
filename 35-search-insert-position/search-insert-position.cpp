class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx=-1;
        int si=0;
        int ei=nums.size()-1;
        while(si<=ei){
            int mid=si+(ei-si)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                    ei=mid-1;
                    idx=mid;
            }
            else{
                si=mid+1;
                idx=mid+1;
            }
        }
        return idx;
    }
};