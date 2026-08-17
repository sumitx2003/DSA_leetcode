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
        if(head==NULL || head->next==NULL)return NULL;
        
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        count=count/2;
        temp=head;
        ListNode* prev=NULL;
        while(count-- && temp!=NULL){
            prev=temp;
            temp=temp->next;
        } 
       if(temp!=NULL) temp=temp->next;
        if(prev!=NULL)prev->next=temp;
        //prev->next=temp->next;
        return head;
    }
};