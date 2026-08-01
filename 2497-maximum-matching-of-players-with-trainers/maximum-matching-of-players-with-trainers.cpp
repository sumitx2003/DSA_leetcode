class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i=0;
        int j=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int n=players.size();
        int m=trainers.size();
        while(i<n && j<m){
            if(players[i]<=trainers[j]){
                i++;
            
            }
           j++;
        }
        return i;
    }
};