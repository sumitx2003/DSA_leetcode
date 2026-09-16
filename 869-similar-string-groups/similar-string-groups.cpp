class Solution {
public:
    bool is_swap(string &node,string &neigh){
          int res=0;
          int i=0;
          int j=0;
          while(i<node.length() && j<neigh.length()){
                  if(node[i]!=neigh[j])res++;

                  i++;
                  j++;

          }
          if(res==2)return true;

          return false;

    }
    int numSimilarGroups(vector<string>& strs) {
        string str=strs[0];
        set<string>st;
        set<string>vis;
        for(int i=0;i<strs.size();i++){
             st.insert(strs[i]);
        }
        queue<string>q;
        int count=0;

        for(int i=0;i<strs.size();i++){
             if(vis.find(strs[i])!=vis.end())continue;

             q.push(strs[i]);
             vis.insert(strs[i]);
             
             while(!q.empty()){
                   int N=q.size();
                   while(N--){
                       string node=q.front();
                       q.pop();

                       for(int j=0;j<strs.size();j++){
                             string neigh=strs[j];
                             if(vis.find(neigh)==vis.end() && is_swap(node,neigh) && node!=neigh){
                                   vis.insert(neigh);
                                   q.push(neigh);
                             }
                       }
                   }
             }
             count++;
        }
        return count;
    }
};