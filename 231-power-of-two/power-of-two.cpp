class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x=n;
        if(x<=0)return false;

        if(x==1)return true;
        while(x>1){
            if(x%2!=0)return false;

            x=x/2;
        }
        return true;
    }
};