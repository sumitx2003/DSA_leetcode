class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>>mp;

        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]={i,i};
            }
            else{
                int x=mp[s[i]].first;
                mp[s[i]]={x,i};
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto& it:mp){
            pair<int,int>p=it.second;
            pq.push({p.first,p.second});
        }
        vector<int>vec;
        while(!pq.empty()){

            if(pq.size()==1){
                int a=pq.top().first;
                int b=pq.top().second;
                pq.pop();
                vec.push_back(b-a+1);
                break;
            }
            int a=pq.top().first;
            int b=pq.top().second;
            pq.pop();

            int c=pq.top().first;
            int d=pq.top().second;
            pq.pop();

            if((a<=c && a<=d) && (b>=c && b>=d)){
                pq.push({a,b});
            }
            else if((a<=c && a<=d) && (b>=c && b<d)){
                pq.push({a,d});
            }
            else{
                vec.push_back(b-a+1);
                pq.push({c,d});
            }

        }
        return vec;

    }
};