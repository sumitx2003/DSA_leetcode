class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        if(word.size()<=8){
            return word.size();
        }
        else if(word.size()>8 && word.size()<=16){
            return 8+(word.size()-8)*2;
        }
        else if(word.size()>16 && word.size()<=24){
            return 24+(word.size()-16)*3;
        }
        else {
            return 48+(word.size()-24)*4;
        }
        return -1;
    }
};