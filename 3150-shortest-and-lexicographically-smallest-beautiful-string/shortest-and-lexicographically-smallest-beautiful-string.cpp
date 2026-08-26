class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {


        int l=0;
        int r=0;

        int min_len=INT_MAX;
        string sub;
        int n=s.size();

        int cnt=0;

        int len;

        while(r<n){

            while(r<n && cnt<k){

                if(s[r]=='1') cnt++;

                r++;
            }

            if(cnt==k){

                // remove the all char '0'
                while(l<n && s[l]=='0'){
                    l++;
                }

                len=r-l;

                if(min_len>len){
                    sub=s.substr(l,len);
                }


                if(min_len==len){
                    sub=min(sub,s.substr(l,len));
                }

                min_len=min(min_len,len);

                // put l to 2nd number of '1'
                while(l<n && cnt>=k-1){
                    if(s[l]=='1' && cnt==k-1) break;
                    if(s[l]=='1' && cnt==k) cnt--;
                    l++;
                }
            }
        }

        return sub;
        
    }
};