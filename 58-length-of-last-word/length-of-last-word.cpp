class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.length()-1;
        if(s.length()==0)return 0;
        while(j>=0 && s[j]==' '){
            j--;
        }
        int count =0;
        while(j>=0 && s[j]!=' '){
            count++;
            j--;
        }
        return count;
    }
};