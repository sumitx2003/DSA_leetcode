class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count=0;
        int i=0;
        while(i<s.length()){
             if(s[i]=='('){
                  st.push('(');
             }
             else{
                  if(st.size()>0){
                      st.pop();
                  }
                  else if(st.size()==0){
                         count++;
                  }
             }
             i++;
        }
        return count+st.size();
    }
};