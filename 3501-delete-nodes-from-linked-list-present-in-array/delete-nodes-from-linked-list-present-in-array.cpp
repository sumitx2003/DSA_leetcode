/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            if(st.find(temp->val)!=st.end()){
                if(temp==head){
                    head=head->next;
                    temp->next=NULL;
                    temp=head;
                }
                else{
                    ListNode* node=temp->next;
                    temp->next=NULL;
                    prev->next=node;
                    temp=node;
                }
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};