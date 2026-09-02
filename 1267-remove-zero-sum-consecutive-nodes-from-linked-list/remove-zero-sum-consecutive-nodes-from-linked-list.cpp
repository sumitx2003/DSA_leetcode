class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int>vec;
        ListNode* temp=head;

        while(temp){
            vec.push_back(temp->val);
            temp=temp->next;
        }

        vector<int>nums;
        for(int i=0;i<vec.size();i++){
            if(vec[i]!=0){
                nums.push_back(vec[i]);
            }
        }

        while(true){
            int j=0;
            int sum=0;
            int len=0;
            int x=-1;
            int y=-1;

            unordered_map<int,int>mp;
            mp[0]=-1;

            while(j<nums.size()){
                sum+=nums[j];

                if(mp.find(sum)==mp.end()){
                    mp[sum]=j;
                }
                else{
                    int len1=j-mp[sum];

                    if(len1>len){
                        len=len1;
                        x=mp[sum]+1;
                        y=j;
                    }
                }
                j++;
            }

            // No zero-sum subarray found
            if(x==-1)
                break;

            vector<int>newNums;

            for(int i=0;i<nums.size();i++){
                if(i<x || i>y){
                    newNums.push_back(nums[i]);
                }
            }

            nums=newNums;
        }

        ListNode* list1=new ListNode(0);
        temp=list1;

        for(int i=0;i<nums.size();i++){
            ListNode* node=new ListNode(nums[i]);
            temp->next=node;
            temp=temp->next;
        }

        return list1->next;
    }
};