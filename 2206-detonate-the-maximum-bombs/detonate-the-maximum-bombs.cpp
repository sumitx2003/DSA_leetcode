class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
          int maxi=INT_MIN;
          map<tuple<int,int,int>,int>mp;
         for(int i=0;i<bombs.size();i++){
            
              int u=bombs[i][0];
              int v=bombs[i][1];
              int r=bombs[i][2];

              mp[{u,v,r}]++;

         }  

          for(int i=0;i<bombs.size();i++){
              int u=bombs[i][0];
              int v=bombs[i][1];
              int r=bombs[i][2];
              

              set<pair<int,int>>vis;
              queue<tuple<int,int,int>>q;
              map<tuple<int,int,int>,int>mp1=mp;
              
              int count=1;
              q.push({u,v,r});

              vis.insert({u,v});
              mp1[{u,v,r}]--;

              while(!q.empty()){
                
                   int N=q.size();
                   while(N--){
                        auto [x,y,w]=q.front();
                        q.pop();

                        for(int j=0;j<bombs.size();j++){
                              int x1=bombs[j][0];
                              int y1=bombs[j][1];
                              int r1=bombs[j][2];

                              if(mp1[{x1,y1,r1}]>0){
                                     double dis=sqrt(abs(1LL*(x-x1)*(x-x1) + 1LL*(y-y1)*(y-y1)));

                                     if(w>=dis){
                                          count++;
                                          q.push({x1,y1,r1});
                                         // vis.insert({x1,y1});
                                         mp1[{x1,y1,r1}]--;
                                     }
                              }
                        }
                   }
              }
              maxi=max(maxi,count);
          }
          return maxi;
    } 
};