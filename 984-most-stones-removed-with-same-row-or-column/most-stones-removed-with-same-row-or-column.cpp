class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxcount=0;
        set<pair<int,int>>vis;
        for(int i=0;i<stones.size();i++){
            int a=stones[i][0];
            int b=stones[i][1];

            if(vis.find({a,b})!=vis.end())continue;

            int count=0;
            queue<pair<int,int>>q;
           

           q.push({a,b});
          vis.insert({a,b});

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                count++;

                for(int i=0;i<stones.size();i++){
                      int u=stones[i][0];
                      int v=stones[i][1];

                      if((x==u || y==v) && vis.find({u,v})==vis.end()){
                          q.push({u,v});
                          vis.insert({u,v});
                          
                      }
                }
                
            }
        }  
        maxcount+=count-1;
          
    }
      
        return maxcount;
    }
};