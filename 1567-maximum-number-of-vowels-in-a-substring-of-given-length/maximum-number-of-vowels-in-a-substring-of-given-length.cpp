class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0;
        int i=0;
        int j=0;
        int ans=INT_MIN;
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        while(j<s.length()){
            if(j-i+1<k){
                if(st.find(s[j])!=st.end()){
                    count++;
                    ans=max(ans,count);
                }
            }
            else if(j-i+1==k){
                if(st.find(s[j])!=st.end()){
                    count++;
                    ans=max(ans,count);
                }
                if(st.find(s[i])!=st.end()){
                    count--;
                    
                }
                i++;
            }
            j++;
        } 
        if(ans!=INT_MIN)return ans;
        
        return 0;
    }
};