class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
        int j=people.size()-1;
        int count=0;
        vector<bool>vis(people.size(),0);

        sort(people.begin(),people.end());
        while(i<j){
            if((people[i]+people[j])<=limit){
                count++;
                vis[i]=1;
                vis[j]=1;
                i++;
                j--;
            }
            else{
                count++;
                vis[j]=1;
                j--;
            }
        }
        if(i==j && vis[i]==0)count++;

        return count;
    }
};