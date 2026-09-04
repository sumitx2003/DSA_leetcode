class Solution {
public:
    string compressedString(string word) {
        int count=1;
        string str="";
        if(word.length()==0)return "";
        int i=0;
        while(i<word.length()-1){
            if(word[i]==word[i+1] && count<9){
                count++;
                i++;
            }
            else if(count==9){
                str+=to_string(count)+word[i];
                count=1;
                i++;
            }
            else{
                str+=to_string(count)+word[i];
                count=1;
                i++;
            }
        }
        if(count!=0){
            str+=to_string(count)+word[i];
        }
        return str;
    }
};