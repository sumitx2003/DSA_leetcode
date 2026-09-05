class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                if(s[i]=='('){
                    st.push(s[i]);
                }
                else{
                    count++;
                }
            }
            else{
                if(s[i]=='('){
                    st.push(s[i]);

                }
                else{
                    st.pop();
                }
            }
        }
        return count+st.size();
    }
};