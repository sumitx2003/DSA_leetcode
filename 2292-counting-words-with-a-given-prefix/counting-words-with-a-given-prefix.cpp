class Solution {
public:
    bool solve(string &str1,string &str2){
        string s1=str1;
        string s2=str2;
        if(s1.length()>s2.length())return false;

        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])return false;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int count=0;

        for(int i=0;i<words.size();i++){
            bool ans=false;
            ans=solve(pref,words[i]);
            if(ans==true)count++;
        }
        return count;
    }
};