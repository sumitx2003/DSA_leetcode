class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<intervals.size();i++){
            int u=intervals[i][0];
            int v=intervals[i][1];

            pq.push({u,v});
        }
        int count=0;
        while(!pq.empty()){

            if(pq.size()==1){
                count++;
                break;
            }
            int  a=pq.top().first;
            int b=pq.top().second;
            pq.pop();

            int c=pq.top().first;
            int d=pq.top().second;
            pq.pop();

            if((a==c) && (b<=d)){
                
                pq.push({a,d});
            }

            else if((a<=c && a<=d) && (b>=c && b>=d)){
                 pq.push({a,b});
            }
            else{
                count++;
                pq.push({c,d});
            }
        }
        return count;
    }
};