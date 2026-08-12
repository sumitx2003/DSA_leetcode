class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int j=0;
        int i=0;
        int len=INT_MIN;
        while(j<nums.size()){
            if(mp.find(nums[j])==mp.end() || mp[nums[j]]<k){
                mp[nums[j]]++;
                len=max(len,j-i+1);
            
            }
            else if(mp[nums[j]]==k){
                  len=max(len,j-i);
                  
                  while(mp[nums[j]]>=k){
                        mp[nums[i]]--;
                        i++;
                  }
                  mp[nums[j]]++;      
            }
            j++;
        }
        return len;
    }
};