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
    ListNode* oddEvenList(ListNode* head) {

        if(head==NULL || head->next==NULL)return head;

       ListNode* odd=head;
       ListNode* odd1=head;
       ListNode* even=head->next;
       ListNode* even1=head->next;

       ListNode* temp=even->next;

       int i=1;
       while(temp!=NULL){
        ListNode* next=temp->next;
          if(i%2!=0){
              odd->next=temp;
              odd=odd->next;
          }
          else{
            even->next=temp;
            even=even->next;
          }
          temp=next;
         
          i++;
       }
        even->next=NULL;
        odd->next=even1;
       return odd1;
        
    }
};