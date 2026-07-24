class Solution {
public:
    bool solve(string &str1,string &str2){
        
        string s1=str1;
        string s2=str2;
        if(s1.length()>s2.length())return false;
        
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])return false;
        }
        int j=s2.length()-1;
        for(int i=s1.length()-1;i>=0;i--){
              if(s1[i]!=s2[j])return false;
              j--;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
         int count=0;
         for(int i=0;i<words.size();i++){
               string str1=words[i];
            for(int j=i+1;j<words.size();j++){
                string str2=words[j];
                bool ans=false;
                ans=solve(str1,str2);
                if(ans==true)count++;
            }
         }
         return count;
    }
};