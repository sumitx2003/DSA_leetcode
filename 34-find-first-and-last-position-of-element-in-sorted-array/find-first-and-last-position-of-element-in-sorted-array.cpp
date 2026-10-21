class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int si=0;
        int ei=nums.size()-1;
        int first=-1;

        while(si<=ei){
             int mid=si+(ei-si)/2;
             if(nums[mid]==target){
                  first=mid;
                  ei=mid-1;
             }
             else if(nums[mid]>target){
                  ei=mid-1;
             }
             else{
                  si=mid+1;
             }
        }
        int last=-1;
        si=0;
        ei=nums.size()-1;
        while(si<=ei){
             int mid=si+(ei-si)/2;
             if(nums[mid]==target){
                  last=mid;
                  si=mid+1;
             }
             else if(nums[mid]>target){
                  ei=mid-1;
             }
             else{
                  si=mid+1;
             }
        }
        return {first,last};
    }
};