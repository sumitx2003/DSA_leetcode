class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
             nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        long long sum=0;
        bool oddturn=true;
        int count=0;
        while(i<j){
            if(oddturn){
                oddturn=false;
                sum+=nums[j]*nums[j];
                j--; 
            }
            else{
                oddturn=true;
                sum-=nums[i]*nums[i];
                i++;
            }
            count++;
        }
        if(count!=nums.size()){
              if(oddturn==true){
                  sum+=nums[j]*nums[j];
              }
              else{
                  sum-=nums[i]*nums[i];
              }
        }
        return sum;
    }
};