class Solution {
public:
    vector<string>vec;
    int N;
    void solve(int open,int close,string & s){
        if(s.length()==2*N){
             if(open==close)vec.push_back(s);

             return ;
        }
         if(open<N){
             s.push_back('(');
             solve(open+1,close,s);
             s.pop_back();
         }
         if(close<open && close<N){
              s.push_back(')');
              solve(open,close+1,s);
              s.pop_back();
         }
        
    }
    vector<string> generateParenthesis(int n) {
        N=n;
        string s="";
        solve(0,0,s);
        return vec;
    }
};