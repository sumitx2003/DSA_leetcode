class Solution {
public:
    int t[500][500][2];
    int solve(vector<int>&piles,int i,int j,bool flag){
        if(i>j)return 0;

        int ans=INT_MIN;

        if(t[i][j][flag]!=-1)return t[i][j][flag];

        if(flag==true){
            int start=piles[i]+solve(piles,i+1,j,!flag);
            int end=piles[j]+solve(piles,i,j-1,!flag);
            ans=max(start,end);
        }else{
            int start=solve(piles,i+1,j,!flag);
            int end=solve(piles,i,j-1,!flag);
            ans=max(start,end);
        }
        return t[i][j][flag]=ans;
    } 
    bool stoneGame(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        int n=piles.size()-1;
        int x=solve(piles,0,n,true);

        int sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=piles[i];
        }
        if(sum-x>x)return false;

        return true;
        
    }
};