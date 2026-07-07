class Solution {
public:
    long long sumAndMultiply(int n) {

        if(n==0)return 0;
        long long sum=0;
        string str="";

        while(n){
            sum+=n%10;
            if(n%10!=0){
                str+=to_string(n%10);
            }
            n=n/10;
        }
        reverse(str.begin(),str.end());
        return sum*(stoll(str));
    }
};