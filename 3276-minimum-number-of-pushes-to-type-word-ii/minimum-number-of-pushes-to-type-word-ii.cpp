class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        priority_queue<int>pq;
        for(auto &it:mp){
            pq.push(it.second);
        }
        int sum=0;
        int k=8;
        while(!pq.empty() && k--){
            sum+=pq.top();
            pq.pop();
        }
        k=8;
        while(!pq.empty() && k--){
            sum+=pq.top()*2;
            pq.pop();
        }
        k=8;
        while(!pq.empty() && k--){
            sum+=pq.top()*3;
            pq.pop();
        }
        k=2;
        while(!pq.empty() && k--){
            sum+=pq.top()*4;
            pq.pop();
        }
        return sum;
    }
};