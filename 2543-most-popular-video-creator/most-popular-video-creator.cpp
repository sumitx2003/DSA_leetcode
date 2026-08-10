class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,long long>mp;
        unordered_map<string,pair<string,long long >>mp1;

        for(int i=0;i<creators.size();i++){
            string u=creators[i];
            long long v=views[i];
            string id=ids[i];
            mp[u]+=v;
            if(mp1.find(u)==mp1.end()){
                mp1[u]={id,v};
            }
            else{
                if(mp1[u].second<v){
                    mp1[u]={id,v};
                }
                else if(mp1[u].second==v){
                    string s=mp1[u].first;
                    if(id<s){
                        mp1[u]={id,v};
                    }
                }
            }
        }
        priority_queue<pair<long long,string>>pq;
        for(auto &it:mp){
            pq.push({it.second,it.first});
        }
        vector<vector<string>>vec;
        long long x=0;
        if(!pq.empty()){
            x=pq.top().first;
        }
        while(!pq.empty() && x<=pq.top().first){
            vector<string>ans;
            long long y=pq.top().first;
            string s=pq.top().second;
            pq.pop();
            string id=mp1[s].first;
            ans.push_back(s);
            ans.push_back(id);
            vec.push_back(ans);
        }
        return vec;
    }
};