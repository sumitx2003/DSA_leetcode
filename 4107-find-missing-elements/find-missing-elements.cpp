class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        for(int i=mini;i<=maxi;i++){
            if(mp.find(i)==mp.end())ans.push_back(i);
        }
        return ans;
        
    }
};