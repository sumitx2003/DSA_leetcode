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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* curr=head->next;
        
        while(curr){
            int sum=0;
            while( curr && curr->val!=0){
                sum+=curr->val;
                curr=curr->next;
            }
            if(curr && curr->val==0){
                ListNode* node=new ListNode(sum);
                temp->next=node;
                node->next=curr;
                temp=curr;
                curr=curr->next;
            }
        }
        curr=head->next;
        temp=curr;
        while(curr && curr->next){
              ListNode* t=curr->next->next;
               curr->next=t;
               curr=t;

        }
        return temp;
    }
};