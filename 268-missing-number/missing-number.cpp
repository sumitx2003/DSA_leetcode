class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++){
            result=result^nums[i];
        }
        for(int i=0;i<=nums.size();i++){
            result=result^i;
        }
        return result;
    }
};