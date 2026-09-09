class Solution {
public:
    long long countCommas(long long n) {
        long long count=0;
        long long base=1000;
        int com=1;
        while(base<=n){
            long long upper=min(n,base*1000-1);
            
            count+=(upper-base+1)*com;
            base*=1000;
            com++;
        }
        return count;
    }
};