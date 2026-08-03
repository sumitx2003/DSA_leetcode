class Solution {
public:
    int n;
    int t[50001][2];
    int solve(vector<int>&stoneValue,int i,bool flag){
        if(i>=stoneValue.size())return 0;

        int ans=INT_MIN;
        int ans1=INT_MAX;

        if(t[i][flag]!=-1)return t[i][flag];
        
        if(flag==true){
             if(n-i>=3){
            int take1=stoneValue[i]+solve(stoneValue,i+1,!flag);
            int take2=stoneValue[i]+stoneValue[i+1]+solve(stoneValue,i+2,!flag);
            int take3=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]+solve(stoneValue,i+3,!flag);

            int x=max(max(take1,take2),take3);

            ans=max(ans,x);
        }
        else if(n-i==2){
            int take1=stoneValue[i]+solve(stoneValue,i+1,!flag);
            int take2=stoneValue[i]+stoneValue[i+1]+solve(stoneValue,i+2,!flag);

            ans=max(ans,max(take1,take2));
        }
        else if(n-i==1){
            int take1=stoneValue[i]+solve(stoneValue,i+1,!flag);

            ans=max(ans,take1);
        }
    }
    else{
          if(n-i>=3){
            int take1=solve(stoneValue,i+1,!flag);
            int take2=solve(stoneValue,i+2,!flag);
            int take3=solve(stoneValue,i+3,!flag);

            int x=min(min(take1,take2),take3);

            ans1=min(ans1,x);


            return t[i][flag]=ans1;
        }
        else if(n-i==2){
            int take1=solve(stoneValue,i+1,!flag);
            int take2=solve(stoneValue,i+2,!flag);

            ans1=min(ans1,min(take1,take2));
            return t[i][flag]=ans1;
        }
        else if(n-i==1){
            int take1=solve(stoneValue,i+1,!flag);

            ans1=min(ans1,take1);

            return t[i][flag]=ans1;
        }

    }  
      return t[i][flag]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
         memset(t,-1,sizeof(t));
         n=stoneValue.size();
         int x=solve(stoneValue,0,true);

         int s=0;

         for(int i=0;i<stoneValue.size();i++){
            s+=stoneValue[i];
         }
         if(s-x<x)return "Alice";

         if(s-x==x)return "Tie";

         return "Bob";
    }
};