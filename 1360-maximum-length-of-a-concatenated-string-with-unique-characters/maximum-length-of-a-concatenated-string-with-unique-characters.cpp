class Solution {
public:
    bool hasDuplicate(string str1,string str2){
           vector<int>vec(26,0);
           for(int i=0;i<str1.length();i++){
                if(vec[str1[i]-'a']>0){
                    return true;
                }
                else{
                    vec[str1[i]-'a']++;
                }
           }
           for(int i=0;i<str2.length();i++){
              if(vec[str2[i]-'a']>0){
                return true;
            }
            else{
                vec[str2[i]-'a']++;
            }

           }
           return false;
    }

    int solve(vector<string>& arr,string str,int idx){
          if(idx>=arr.size())return str.length();

          int include=0;
          int exclude=solve(arr,str,idx+1);

          if(!hasDuplicate(str,arr[idx])){
              include=solve(arr,str+arr[idx],idx+1);
          }
          return max(include,exclude);
    }

    int maxLength(vector<string>& arr) {
        return solve(arr, "", 0);
    }
};
