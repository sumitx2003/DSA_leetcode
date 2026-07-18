class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=INT_MIN;
        int mn=INT_MAX;

        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
        int x=1;

        for(int i=1;i<=mn;i++){
            if(mx%i==0 && mn%i==0)x=i;
        }
        return x;

    }
};