class Solution {
public:
    int result;
    int solve(unordered_map<int,vector<int>>&mp,int curr,int parent,string &s){
          int longest=0;
          int second_longest=0;

          for(int &child:mp[curr]){
              if(child==parent)continue;

              int child_longest_length=solve(mp,child,curr,s);

              if(s[child]==s[curr])continue;

              if(child_longest_length>second_longest)second_longest=child_longest_length;

              if(second_longest>longest)swap(longest,second_longest);
          }
         int koi_ek_acha=max(longest,second_longest)+1;
         int only_root_acha=1;
         int neeche_hi_milgaya_answer=1+longest+second_longest;

         result=max({result,koi_ek_acha,neeche_hi_milgaya_answer}); 

         return max(koi_ek_acha,only_root_acha);
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        unordered_map<int,vector<int>>mp;

        result=0;

        for(int i=1;i<n;i++){
            int u=i;
            int v=parent[i];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        solve(mp,0,-1,s);
        return result;

    }
};