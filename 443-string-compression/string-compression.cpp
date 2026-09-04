class Solution {
public:
    int compress(vector<char>& chars) {
        int count=1;
        int i=0;
        string str="";
        if(chars.size()==0)return 0;
        if(chars.size()==1)return 1;
        while(i<chars.size()-1){
             if(chars[i]==chars[i+1]){
                  count++;
                  i++;
             }
             else{
                if(count==1){
                   str+=chars[i];
                   count=1;
                }
                else{
                    str+=chars[i]+to_string(count);
                    count=1;
                }
                
                i++;
             }
        }
        if(count!=0){
            if(count==1){
                str+=chars[i];
            }
            else{
                str+=chars[i]+to_string(count);
            }
            
        }

        for(int i=0;i<str.length();i++){
              chars[i]=str[i];
        }
       return str.length();
    }
};