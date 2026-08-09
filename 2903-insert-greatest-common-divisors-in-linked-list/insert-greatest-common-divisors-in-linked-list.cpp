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
    int gcd(int a,int b){
        if(a==b)return a;

        while(b!=0){
            int rem=a%b;
            a=b;
            b=rem;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* prev=head;

        while(temp!=NULL){
            int x=1;
            if(temp->val>=prev->val){
                x=gcd(temp->val,prev->val);
            }
            else{
                x=gcd(prev->val,temp->val);
            }
            ListNode* temp1=new ListNode(x);
            prev->next=temp1;
            temp1->next=temp;
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};