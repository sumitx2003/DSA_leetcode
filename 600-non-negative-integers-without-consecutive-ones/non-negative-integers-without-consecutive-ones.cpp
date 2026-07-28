class Solution {
public:
    string bits;
    int t[32][2][2];
    int solve(int pos,bool tight,bool prevOne){
        if(pos==bits.size())return 1;

        if(t[pos][tight][prevOne]!=-1)return t[pos][tight][prevOne];

        int limit=tight ? bits[pos]-'0':1;
        int ans=0;

        for(int d=0;d<=limit;d++){
            if(prevOne==1 && d==1)continue;

            bool newtight=tight && (d==limit);

            ans+=solve(pos+1,newtight,d==1);
        }

        if(!tight){
            t[pos][tight][prevOne]=ans;
        } 
        return ans;
    }
    int findIntegers(int n) {
        memset(t,-1,sizeof(t));
        bits="";
        while(n){
            bits.push_back((n%2)+'0');
            n=n/2;
        }
        if(bits==""){
            bits="0";
        }
        reverse(bits.begin(),bits.end());

       return solve(0,true,false);
    }
};