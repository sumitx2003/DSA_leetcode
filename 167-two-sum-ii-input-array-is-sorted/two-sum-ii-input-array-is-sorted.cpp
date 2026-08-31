class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        while(i<numbers.size()-1){
               int si=i+1;
               int ei=numbers.size()-1;
               while(si<=ei){
                  int mid=(si+ei)/2;
                  if(target-numbers[i]==numbers[mid]){
                    return {i+1,mid+1};
                  }
                  else if((target-numbers[i])>numbers[mid]){
                         si=mid+1;
                  }
                  else {
                        ei=mid-1;
                  }
               }
               i++;
        }
        return {0,0};
    }
};