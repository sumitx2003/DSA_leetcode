class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int si=0;
        int ei=nums.size()-1;
        while(si<=ei){
             int mid=si+(ei-si)/2;

             if(nums[mid]==target){
                 return true;
             }
             else if(nums[mid]>target){
                if(nums[mid]==nums[si]){
                     si++;
                }
                else if(nums[si]<=target){
                      ei=mid-1;
                 }
                 else if(nums[si]>target && (nums[si]<=nums[mid])){
                        si=mid+1;
                 }
                 else{
                       ei=mid-1;
                 }
             }
             else{
                if(nums[mid]==nums[ei]){
                      ei--;
                }
                 else if(nums[ei]>=target){
                      si=mid+1;
                  }
                  else if(nums[ei]<target && (nums[mid]<nums[ei])){
                      ei=mid-1;
                  }
                  else{
                      si=mid+1;
                  }
             }
        }
        return false;
    }
};