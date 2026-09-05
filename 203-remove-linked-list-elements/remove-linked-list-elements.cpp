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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=head;
        ListNode* prev=new ListNode(0);
        prev->next=head;
        ListNode* dummy=prev;

        while(temp){
            if(temp->val==val ){
                temp=temp->next;
                prev->next=temp;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        if(prev->val==0)return NULL;

        return  dummy->next;
    }
};