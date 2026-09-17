class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
          if(roads.size()==0)return 0;
           unordered_map<int,vector<int>>mp;
           set<pair<int,int>>st;
           for(int i=0;i<roads.size();i++){
                  int u=roads[i][0];
                  int v=roads[i][1];

                  mp[u].push_back(v);
                  mp[v].push_back(u);
                  st.insert({u,v});

           }
           int maxi=INT_MIN;
            vector<pair<int,int>>vec;
            for(auto &it:mp){
                vec.push_back({it.first,it.second.size()});
            }
            for(int i=0;i<vec.size();i++){
                 int u=vec[i].first;
                 int v=vec[i].second;
                 for(int j=0;j<vec.size();j++){
                      if(j==i)continue;

                      if(st.find({u,vec[j].first})!=st.end() || 
                         st.find({vec[j].first,u})!=st.end()){
                             maxi=max(v+vec[j].second-1,maxi);
                      }
                      else{
                           maxi=max(maxi,v+vec[j].second);
                      }
                 }
            }
           return maxi;
        
    }
};