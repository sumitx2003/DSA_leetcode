class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        int len=0;
        unordered_map<char,int>mp;
        while(j<s.length()){
            if(mp.find(s[j])==mp.end()){
                 mp[s[j]]++;
                 len=max(len,j-i+1);
            }
            else if(mp.find(s[j])!=mp.end() && mp[s[j]]<2){
                  mp[s[j]]++;
                  len=max(len,j-i+1);
            }
            else if(mp.find(s[j])!=mp.end() && mp[s[j]]==2){
                   mp[s[j]]++;
                   while(mp[s[j]]>2){
                      mp[s[i]]--;
                      i++;
                   }
                   len=max(len,j-i+1);
            }
            j++;
        }
        return len;
    }
};