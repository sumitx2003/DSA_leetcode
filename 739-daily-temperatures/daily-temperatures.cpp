class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans(temperatures.size(),0);
        int i=0;
        while(i<temperatures.size()){
            if(st.empty()){
                st.push(i);
            }
            else{
                if(temperatures[st.top()]>temperatures[i]){
                    st.push(i);
                }
                else{
                    while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                          ans[st.top()]=(i-st.top());
                          st.pop();
                    }
                    st.push(i);
                }
            }
            i++;
        }
        return ans;
    }
};