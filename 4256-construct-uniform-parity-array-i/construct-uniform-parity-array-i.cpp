class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
         int odd = 0;

        for(int x : nums1){
            if(x % 2) odd++;
        }

        if(odd==0 || odd>=1)return true;

        return false;
    }
};