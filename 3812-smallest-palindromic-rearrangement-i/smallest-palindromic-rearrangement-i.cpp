class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(),s.end());
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        char ch;
        for(auto &it:mp){
           if(it.second%2==1){
            ch=it.first;
           } 
        }
        string s1="";
        string s2="";
        string middle="";
        int i=0;
        while(i<s.length()){
            if(s[i]==ch){
                middle+=s[i];
                int x=mp[s[i]];
                int y=x/2;
                while(y){
                    s1+=s[i];
                    s2+=s[i];
                    y--;
                }
                i+=x;
            }
            else{
                s1+=s[i];
                s2+=s[i+1];
                i+=2;
            }
        }
        string str;
         reverse(s2.begin(),s2.end());
         str+=s1+middle+s2;
        return str;
    }
};