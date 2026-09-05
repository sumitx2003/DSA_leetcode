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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         int count=0;
         ListNode* temp=head;
         while(temp){
            count++;
            temp=temp->next;
         }
         temp=head;
         count=count-n;
         ListNode* prev=NULL;
         
         while(count--){
              prev=temp;
              temp=temp->next;
         }
         if(prev!=NULL && temp!=NULL){
            prev->next=temp->next;
            
         }
         if(prev==NULL)return head->next;
         
         return head;
         
    }
};