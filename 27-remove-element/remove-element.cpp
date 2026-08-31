class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val)count++;
        }
        vector<int>vec;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                vec.push_back(nums[i]);
            }
        }
        for(int j=0;j<nums.size();j++){
             nums[j]=-1;
             if(j<vec.size()){
                nums[j]=vec[j];
             }
        }
        return count;
    }
};