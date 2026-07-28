class Solution {
public:
    int t[20001];
    int solve(vector<int>&vec,int idx,unordered_map<int,int>&mp){
        if(idx>=vec.size())return 0;

        if(t[idx]!=-1)return t[idx];

        int skip=solve(vec,idx+1,mp);

        int take=vec[idx]*mp[vec[idx]];
        
        if(idx+1<vec.size() && vec[idx+1]==(vec[idx]+1)){
            take+=solve(vec,idx+2,mp);
        }
        else{
            take+=solve(vec,idx+1,mp);
        }
        return  t[idx]=max(skip,take);

    }
    int deleteAndEarn(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
      
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>vec;
        for(auto &it:mp){
             vec.push_back(it.first);
        }
        sort(vec.begin(),vec.end());
        return solve(vec,0,mp);
        
    }
};