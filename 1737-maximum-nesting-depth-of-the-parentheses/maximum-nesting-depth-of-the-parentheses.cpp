class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int n = s.length();
        int ans = INT_MIN;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                count++;
            }
            else if(s[i] == ')'){
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
        
    }
};