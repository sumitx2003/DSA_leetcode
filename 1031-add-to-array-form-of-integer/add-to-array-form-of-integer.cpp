class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int cary=0;
        int j=num.size()-1;
        while(j>=0 && k){
            int x=(num[j]+k%10+cary);
            cary=x/10;
            num[j]=x%10;
            k=k/10;
            j--;
        }
        if(k>0){
            reverse(num.begin(),num.end());
            while(k){
                int x=k%10+cary;
                num.push_back(x%10);
                cary=x/10;
                k=k/10;
            }
            reverse(num.begin(),num.end());
        }

        if(cary>0){
            while(j>=0 && cary>0){
                int x=num[j]+cary;
                num[j]=x%10;
                cary=x/10;
                j--;
            }
            if(cary>0){
                num.insert(num.begin(),cary);
            }
        }
        
        return num;
    }
};