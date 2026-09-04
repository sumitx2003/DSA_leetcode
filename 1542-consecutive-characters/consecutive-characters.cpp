class Solution {
public:
    int maxPower(string s) {
         int i=0;
         char prev=s[i];
         int len=1;
         int maxlen=1;
         while(i<s.length()){
            if(i==0){
                len=1;
                i++;
            }
            else{
                if(s[i]==prev){
                    len++;
                    maxlen=max(maxlen,len);
                    prev=s[i];
                    i++;
                }
                else if(s[i]!=prev){
                    len=1;
                    prev=s[i];
                    i++;
                }
            }
         } 
         return maxlen;
    }
};