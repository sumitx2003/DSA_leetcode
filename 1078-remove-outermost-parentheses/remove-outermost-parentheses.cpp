class Solution {
public:
    string removeOuterParentheses(string s) {
        int level=0;
        string str="";
        for(int i=0;i<s.length();i++){
             if(s[i]=='('){
                 level++;
                 if(level>1){
                    str.push_back('(');
                 }
             }
                 else if(s[i]==')'){
                     if(level>1){
                          str.push_back(')');
                     }
                     level--;
                 } 
        }
        return str;
    }
};