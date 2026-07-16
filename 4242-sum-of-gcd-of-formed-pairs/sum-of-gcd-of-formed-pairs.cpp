class Solution {
public:
      int gcd(int a,int b){
        if(b==0)return a;
        if(b>a){
          return gcd(b,a);
        }
        else{
           return gcd(b,a%b);
        }
          return 0;
    }
    long long gcdSum(vector<int>& nums) {
         vector<long long>mxi;
        int m=nums[0];
        for(int i=0;i<nums.size();i++){
            m=max(m,nums[i]);
            mxi.push_back(m);
        }
        vector<long long>prefgcd;
       for(int i=0;i<nums.size();i++){
           long long x=gcd(nums[i],mxi[i]);
           prefgcd.push_back(x);
       }  
        sort(prefgcd.begin(),prefgcd.end());
        int i=0;
        int j=prefgcd.size()-1;
        long long sum=0;
        while(i<j){
            long long x=gcd(prefgcd[i],prefgcd[j]);
            sum+=x;
            i++;
            j--;
        }
        return sum;
    }
};