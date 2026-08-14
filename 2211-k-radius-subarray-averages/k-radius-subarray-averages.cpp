class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>ans(nums.size(),-1);
        long long avg=0;
        int i=0;
        int j=0;
        while(j<nums.size()){
             if(j-i+1<2*k+1){
                avg+=nums[j];
             }
             else if(j-i+1==2*k+1){
                   avg+=nums[j];
                   ans[(j+i)/2]=avg/(2*k+1);
                   avg=avg-nums[i];
                   i++;
             }
             j++;
        }
        return ans;
    }
};