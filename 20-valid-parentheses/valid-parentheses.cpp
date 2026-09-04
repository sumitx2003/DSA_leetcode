class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                if(s[i]==')' || s[i]=='}' || s[i]==']'){
                    return false;
                }
                else{
                    st.push(s[i]);
                }
            }
               else if(!st.empty()){
                   if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                    st.push(s[i]);
                }
                else{
                    char ch=st.top();
                    if((s[i]==')' && ch=='(') || (s[i]=='}' && ch=='{') || (s[i]==']' && ch=='[')){
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
               }
        }
        if(st.size()==0)return true;
              
            return false;;
    }
};