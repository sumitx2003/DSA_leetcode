class Solution {
public:
    int t[101][101][2];
    int solve(vector<int>&piles,int i,int M,bool flag){
        if(i>=piles.size())return 0;

        if(t[i][M][flag]!=-1)return t[i][M][flag];

        int ans=INT_MIN;
        if(flag==true){
            int x=min(i+2*M-1,(int)piles.size()-1);
            int sum=0;
            for(int j=i;j<=x;j++){
                int a=max(M,j-i+1);
                sum+=piles[j];
               int take=sum+solve(piles,j+1,a,!flag);

               ans=max(ans,take); 
            }
        }
        else{
            int ans1=INT_MAX;
            int x=min(i+2*M-1,(int)piles.size()-1);
            for(int j=i;j<=x;j++){
                int a=max(M,j-i+1);
               int take=solve(piles,j+1,a,!flag);

               ans1=min(ans1,take); 
            }
            return t[i][M][flag]=ans1;

        }
        return t[i][M][flag]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        return solve(piles,0,1,true);
        
    }
};