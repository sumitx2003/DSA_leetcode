class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for(int i=0;i<knowledge.size();i++){
            string a=knowledge[i][0];
            string b=knowledge[i][1];
            m[a]=b;
        }
        string ans="";
        int start=0;
        bool flag=true;
        for(int e=0;e<s.size();e++){
            if(s[e]=='('){
                start=e+1;
                flag=false;
            }
            if(s[e]==')'){
                string key=s.substr(start,e-start);
                if(m.count(key)){
                    ans+=m[key];
                }
                else{
                    ans+='?';
                }
                flag=true;
            }
            if(flag&&s[e]!=')'){
                ans+=s[e];
            }
        }
        return ans;
    }
};