class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0;
        int min_odd=INT_MAX;
        int min_even=INT_MAX;
       for(int i=0;i<nums1.size();i++){
           if(nums1[i]%2!=0){
               min_odd=min(min_odd,nums1[i]);
               odd++;
           }

           if(nums1[i]%2==0){
               min_even=min(min_even,nums1[i]);
           }
       } 
        if((min_even-min_odd>0 && odd>=1) || odd==0)return true;

        return false;
    }
};