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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int>vec;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int i=1;
        while(count>0){
            int x=min(i,count);
            count=count-x;
            vec.push_back(x);
            i++;
        }
        i=0;
        temp=head;
        ListNode* prev=NULL;
        while(i<vec.size()){
            int x=vec[i];
            if(x%2!=0){
                while(x--){
                    prev=temp;
                    temp=temp->next;
                }
            }
            else{
                ListNode* prev1=NULL;
                ListNode* join=temp;
                while(x--){
                    ListNode* temp1=temp->next;
                    temp->next=prev1;
                    prev1=temp;
                    temp=temp1;
                }
                prev->next=prev1;
                join->next=temp;
                prev=join;
            }
            i++;
        }
        return head;
    }
};