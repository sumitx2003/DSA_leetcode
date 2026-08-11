class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int sum=nums[0];
        int res=nums[0];
        int i=1;
        int idx=0;
        int len=1;
        while(i<nums.size()){
            if(nums[i]==nums[i-1]+1){
               if(len<i-idx+1){
                sum+=nums[i];
                len=i-idx+1;
                res=max(res,sum);
               }  
            }
            else{
                break;
            }
            i++;
        }
        while(mp.find(res)!=mp.end()){
              res++;
        }
        return res;
    }
};