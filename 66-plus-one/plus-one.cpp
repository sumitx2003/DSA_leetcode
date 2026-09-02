class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int j=digits.size()-1;
        int cary=0;
        bool added=false;
        while(j>=0){
            int x=0;
            if(added==false){
                x=(digits[j]+cary+1);
                added=true;
            }
            else{
                x=(digits[j]+cary);
            }
            digits[j]=x%10;
            cary=x/10;
            j--;
        }
        if(cary>0){
            digits.insert(digits.begin(),cary);
        }
        return digits;

    }
};