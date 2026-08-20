class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>ans;
        vector<int>vec;
        int prev=nums[0];
       int  prev1=nums[1];
        
        ans.push_back(nums[0]);
        vec.push_back(nums[1]);
        int i=2;
        while(i<nums.size()){
             if(prev>prev1){
                ans.push_back(nums[i]);
                prev=nums[i];
             }
             else{
                vec.push_back(nums[i]);
                prev1=nums[i];
             }
             i++;
        }
        for(int i=0;i<vec.size();i++){
              ans.push_back(vec[i]);
        }
        return ans;
    }
};