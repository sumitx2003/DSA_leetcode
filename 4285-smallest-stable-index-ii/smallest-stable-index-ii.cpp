class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>rightmin=nums;
        for(int i=n-2;i>=0;i--){
            rightmin[i]=min(rightmin[i],rightmin[i+1]);
        }
        int leftmax=INT_MIN;
        for(int i=0;i<n;i++){
            leftmax=max(leftmax,nums[i]);
            if((leftmax-rightmin[i])<=k){
                return i;
            }
        }
        return -1;
    }
};