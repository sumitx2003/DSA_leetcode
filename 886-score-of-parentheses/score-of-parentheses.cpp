class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int i=0;
        st.push(0);
        while(i<s.length()){
              if(s[i]=='('){
                  st.push(0);
              }
              else{
                   int x=st.top();
                   st.pop();
                   if(x==0){
                    st.top()+=1;
                   }
                   else{
                       st.top()+=2*x;
                   }
              }
              i++;
        }
        return st.top();
    }
};