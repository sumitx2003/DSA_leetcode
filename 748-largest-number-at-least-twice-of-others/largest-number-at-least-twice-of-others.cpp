class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=INT_MIN;
        int idx=-1;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                idx=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                continue;
            }
            else{
                if(maxi<2*nums[i])return -1;
            }
        }
        return idx;
    }
};