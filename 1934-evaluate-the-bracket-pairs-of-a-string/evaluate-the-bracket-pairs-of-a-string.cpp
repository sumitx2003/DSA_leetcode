class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
         unordered_map<string,string>mp;
         for(int i=0;i<knowledge.size();i++){
              string u=knowledge[i][0];
              string v=knowledge[i][1];
              mp[u]=v;
         }
         bool turn=false;
         string str="";
         string res="";
         for(int i=0;i<s.length();i++){
              if(s[i]=='('){
                   turn=true;
                   continue;
              } 
              else if(s[i]==')'){
                    if(mp.find(str)!=mp.end()){
                          res+=mp[str];
                          str="";
                    }
                    else{
                        res+="?";
                        str="";
                    }
                    turn=false;

              }
              else if(turn==false){
                   res.push_back(s[i]);
              }
              else if(turn==true){
                   str.push_back(s[i]);
              }
            
         }
         return res;
    }
};