class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>>mp;
        vector<bool>vis(n,0);
        for(int i=0;i<invocations.size();i++){
            int u=invocations[i][0];
            int v=invocations[i][1];
            mp[u].push_back(v);
        }
        queue<int>q;
        q.push(k);
        vis[k]=1;
        unordered_set<int>st;
        st.insert(k);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            vector<int>vec=mp[node];
            for(int i=0;i<vec.size();i++){
                if(!vis[vec[i]]){
                    vis[vec[i]]=1;
                    q.push(vec[i]);
                    st.insert(vec[i]);
                }
            }
        }
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            ans.push_back(i);
        }
        for(int i=0;i<n;i++){
            if(st.find(i)!=st.end())continue;

            vector<int>v=mp[i];
            for(int i=0;i<v.size();i++){
                if(st.find(v[i])!=st.end())return ans;
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end())res.push_back(i);
        }
        return res;
    }
};