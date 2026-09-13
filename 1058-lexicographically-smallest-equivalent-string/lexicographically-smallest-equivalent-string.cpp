class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
          unordered_map<char,vector<char>>mp;
          for(int i=0;i<s1.length();i++){
                char u=s1[i];
                char v=s2[i];
                mp[u].push_back(v);
                mp[v].push_back(u);
          }    
          string ans="";
          for(int i=0;i<baseStr.length();i++){
               queue<char>q;
               char ch=baseStr[i];
               q.push(ch);
               unordered_set<char>vis;
               while(!q.empty()){
                   int N=q.size();
                   while(N--){
                       char node=q.front();
                       q.pop();

                       if(node<ch)ch=node;

                       for(int j=0;j<mp[node].size();j++){
                               char neigh=mp[node][j];
                               if(vis.find(neigh)==vis.end()){
                                     vis.insert(neigh);
                                     q.push(neigh);
                               }
                       }
                   }
               }
               ans.push_back(ch);
          }
          return ans;

    }
};