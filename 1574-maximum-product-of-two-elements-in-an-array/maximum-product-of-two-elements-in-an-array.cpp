class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<2)return 0;

        return ((nums[nums.size()-1]-1)*(nums[nums.size()-2]-1));
    }
};