class Solution {
public:
    int smallestNumber(int n, int t) {
        int j=n;
        while(j<=100){
            int x=j;
            int ans=1;
            while(x){
            ans*=x%10;
            x=x/10;
        }
          if(ans%t==0)return j;
          j++;
        }
        
      return -1;
    }
};