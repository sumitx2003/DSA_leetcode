class Solution {
public:
    int minInsertions(string s) {
        int count=0;
        int ans=0;
        stack<char>st;
        int i=0;
        while(i<s.length()){
             if(s[i]=='('){
                  if(count==0){
                      st.push('(');
                  }
                  else{
                       ans++;
                       if(!st.empty()){
                          st.pop();
                          count=0;
                       }
                       else{
                           ans++;
                           count=0;
                       }
                       st.push('(');
                       
                  }
             }
             else{
                  count++;
                  if(count==2){
                      if(!st.empty()){
                          st.pop();
                          count=0;
                      }
                      else{
                           ans++;
                           count=0;

                      }
                  }
             }
             i++;
        }
        if(st.empty()){
            if(count==0){
                return ans;
            }
            else if(count==1){
                  ans+=2;
                  return ans;
            }
            else{
                 return ans+1;
            }
        }
        else{
            if(count==0){
                 ans+=st.size()*2;
            }
            else{
                  st.pop();
                  ans+=st.size()*2+1;
            }
        }
        return  ans;
    }
};