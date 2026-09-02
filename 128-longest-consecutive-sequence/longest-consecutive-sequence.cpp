class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len=1;
        if(nums.size()==0 || nums.size()==1)return nums.size();

        int maxi=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
           if(nums[i+1]==nums[i]+1){
               len++;
               maxi=max(maxi,len);
           }
           else if(nums[i+1]==nums[i]){
               continue;
           }
           else{
               len=1;
           }
        }
        
        return maxi;
    }
};