class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans(queries.size(),-1);
        unordered_map<string,vector<pair<string,double>>>mp;
        for(int i=0;i<equations.size();i++){
              string u=equations[i][0];
              string v=equations[i][1];
              double w=values[i];
              double w1=1.0/w;
              mp[u].push_back({v,w});
              mp[v].push_back({u,w1});
        }
        for(int i=0;i<queries.size();i++){
              double res=-1.0;
              string src=queries[i][0];
              string des=queries[i][1];


              if(src==des && mp.find(src)!=mp.end()){
                ans[i]=1.0;
              }
              else  if(mp.find(src)==mp.end() || mp.find(des)==mp.end()){
                    ans[i]=-1.0;
              }
              
        else{
              queue<pair<string,double>>q;
              set<pair<string,string>>vis;
              q.push({src,1.0});

              while(!q.empty()){
                   int N=q.size();
                   while(N--){
                       string node=q.front().first;
                       double weight=q.front().second;
                       q.pop();

                       if(node==des){
                        res=weight;
                        break;
                       }

                       for(int j=0;j<mp[node].size();j++){
                            string neigh=mp[node][j].first;
                            double w=mp[node][j].second;

                            if(vis.find({node,neigh})==vis.end() && vis.find({neigh,node})==vis.end()){
                                   vis.insert({node,neigh});
                                   q.push({neigh,w*weight});
                            }
                       }

                   }
              }
                ans[i]=res;
                
        }
              
        }
        return ans;
    }
};