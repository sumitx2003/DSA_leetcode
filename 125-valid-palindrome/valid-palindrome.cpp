class Solution {
public:
    bool isalpha(char ch){
        for(char c='0';c<='9';c++){
            if(ch==c)return false;
        }
        for(char c='A';c<='Z';c++){
              if(ch==c)return false;

              if(ch==tolower(c))return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;

        while(i<j){
            if(isalpha(s[i])){
                i++;
            }
            else if(isalpha(s[j])){
                j--;
            }
            else if(tolower(s[i])==tolower(s[j])){
                i++;
                j--;
            }
            else if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
        }
        return true;
    }
};