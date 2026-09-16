class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
          unordered_map<int,vector<pair<int,double>>>mp;
          for(int i=0;i<edges.size();i++){
                int u=edges[i][0];
                int v=edges[i][1];
                double w=succProb[i];
                
                mp[u].push_back({v,w});
                mp[v].push_back({u,w});
          }
          priority_queue<pair<double,int>>q;
          vector<double>prob(n,0);
          q.push({1,start_node});
          prob[start_node]=1.0;

          while(!q.empty()){
              int N=q.size();
              while(N--){
                   int node=q.top().second;
                   double weight=q.top().first;
                   q.pop();

                   if(node==end_node)return weight;

                   for(int j=0;j<mp[node].size();j++){
                          int neigh=mp[node][j].first;
                          double w=mp[node][j].second;

                          if(prob[neigh]<weight*w){
                              q.push({weight*w,neigh});
                              prob[neigh]=weight*w;
                          }
                   }
              }
          }
          return 0;
    }
};