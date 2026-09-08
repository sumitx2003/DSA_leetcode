class Solution {
public:
    int countCommas(int n) {
       int count=0;
        if(n<=999)return 0;
        
        for(int i=1000;i<=n;i++){
            if(i>=1000 && i<=9999){
                count++;
            }
            else if(i>=10000 && i<=99999){
                count++;
            }
            else{
                count++;
            }
        }
        return count;
    }
};