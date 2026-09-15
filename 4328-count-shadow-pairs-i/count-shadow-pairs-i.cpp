class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        stack<long long>st;
        int i=0;
        long long ans=0;
        unordered_map<int,int>mp;
        while(i<nums.size()){
              if(st.empty()){
                  st.push(nums[i]);
                  mp[nums[i]]++;
                  i++;
              }
              else{
                  if(nums[i]<st.top()){
                       while(!st.empty() && nums[i]<st.top()){
                           mp[st.top()]--;
                           st.pop();
                       }
                  }
                  if(st.empty()){
                        st.push(nums[i]);
                        mp[nums[i]]++;
                  }

                   else if(nums[i]==st.top()){
                          ans+=st.size()-mp[nums[i]];
                          st.push(nums[i]);
                          mp[nums[i]]++;
                  }
                  else if(nums[i]>st.top()){
                       if(mp.find(nums[i])!=mp.end()){
                            ans+=st.size()-mp[nums[i]];
                       }
                       else{
                             ans+=st.size();
                       }
                        
                        st.push(nums[i]);
                        mp[nums[i]]++;
                  }
                  i++;
              }
        }
        return ans;
    }
};