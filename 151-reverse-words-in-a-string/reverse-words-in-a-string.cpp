class Solution {
public:
    string reverseWords(string s) {
        string str="";
        vector<string>vec;
        for(char ch:s){
            if(ch==' '){
                if(str.size()>0){
                    vec.push_back(str);
                    str="";
                }
                continue; 
            }
            str.push_back(ch);
        }
        if(str.length()>0){
           vec.push_back(str);
        }
        
        string ans="";
        if(vec.size()==0)return ans;


        reverse(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            if(i==(vec.size()-1)){
                ans+=vec[i];
            }
            else{
                ans+=vec[i]+" ";
            }
            
        }
        
        return ans;
    }
};