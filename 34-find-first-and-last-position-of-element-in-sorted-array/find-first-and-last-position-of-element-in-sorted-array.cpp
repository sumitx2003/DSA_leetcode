class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int minidx=INT_MAX;
        int maxidx=INT_MIN;
        
        int si=0;
        int ei=nums.size()-1;

        while(si<=ei){
            int mid=si+(ei-si)/2;
            if(nums[mid]==target){
                minidx=min(minidx,mid);
                ei=mid-1;
            }
            else if(nums[mid]<target){
                si=mid+1;
            }
            else{
                ei=mid-1;
            }
        }
        si=0;
        ei=nums.size()-1;
        while(si<=ei){
            int  mid=si+(ei-si)/2;
            if(nums[mid]==target){
                maxidx=max(maxidx,mid);
                si=mid+1;
            }
            else if(nums[mid]<target){
                si=mid+1;
            }
            else{
                ei=mid-1;
            }
        }
        if(minidx!=INT_MAX && maxidx!=INT_MIN)return {minidx,maxidx};

        return {-1,-1};
    }
};