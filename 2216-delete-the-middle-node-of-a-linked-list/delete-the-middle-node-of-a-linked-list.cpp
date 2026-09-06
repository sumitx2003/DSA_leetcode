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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev=new ListNode(0);
        ListNode* dummy=prev;
        prev->next=head;
        ListNode* temp=head;
        int count=0;

        while(temp){
            count++;
            temp=temp->next;
        }
        count=count/2;
        temp=head;
        while(count--){
                prev=temp;
                temp=temp->next;
        }
        if(temp!=NULL && prev!=NULL){
             temp=temp->next;
             prev->next=temp;
        }
       
        return dummy->next;
    }
};