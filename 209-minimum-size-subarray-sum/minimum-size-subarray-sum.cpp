class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int len=INT_MAX;
        while(j<nums.size()){
            if(sum<target){
                sum+=nums[j];
                j++;
            }
            else if(sum==target){
                len=min(len,j-i);
                sum+=nums[j];
                j++;
            }
            else {
                sum=sum-nums[i];
                len=min(len,j-i);
                i++;

            }
    
        }
       while(sum>target && i<nums.size()){
           sum=sum-nums[i];
           len=min(len,j-i);
           i++;
       }
       while(sum==target && i<nums.size()){
          len=min(len,j-i);
          sum=sum-nums[i];
          i++;
       }  
       if(len!=INT_MAX)return len;

        return 0;
    }
};