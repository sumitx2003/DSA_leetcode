class Solution {
public:
    int numberOfSubstrings(string s) {
        int res=0;
        int lastposition[3]={-1,-1,-1};
        for(int i=0;i<s.length();i++){
            lastposition[s[i]-'a']=i;
            int minposition=min(lastposition[0],min(lastposition[1],lastposition[2]));

            res+=minposition+1;
        }
        return res;
    }
};