class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==0)return 0;
        
        int ans=INT_MIN;
        int i=0;
        int j=1;
        int sum=nums[0];
        while(j<nums.size()){
            if(nums[i]<nums[j]){
                sum+=nums[j];
                ans=max(ans,sum);
                i++;
                j++;
            }
            else{
                ans=max(ans,sum);
                sum=nums[j];
                i=j;
                j++;
            }
        }

        if(ans!=INT_MIN)return ans;

        return 0;

    }
};