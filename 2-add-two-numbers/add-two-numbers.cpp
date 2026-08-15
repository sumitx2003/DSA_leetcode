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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>ans;
        ListNode* temp=l1;
        ListNode* temp1=l2;
        int cary=0;

        while(temp!=NULL && temp1!=NULL){
            int x=temp->val;
            int y=temp1->val;
            int z=x+y+cary;
            if(z<10){
                ans.push_back(z);
                cary=0;
            }
            else{
                cary=z/10;
                z=z%10;
                ans.push_back(z);
            }
            temp=temp->next;
            temp1=temp1->next;
        }


        if(temp!=NULL){
            while(temp!=NULL){
                int x=cary+temp->val;
                if(x<10){
                    ans.push_back(x);
                    cary=0;
                }
                else{
                    cary=x/10;
                    x=x%10;
                    ans.push_back(x);
                }
                temp=temp->next;
            }
        }
        if(temp1!=NULL){
            while(temp1!=NULL){
                int x=temp1->val+cary;
                if(x<10){
                    ans.push_back(x);
                    cary=0;
                }
                else{
                    cary=x/10;
                    x=x%10;
                    ans.push_back(x);
                }
                temp1=temp1->next;
            }
        }
        if(cary>0){
            ans.push_back(cary);
        }
        ListNode* node=new ListNode(ans[0]);
        ListNode* node1=node;

        int i=1;
        while(i<ans.size()){
            ListNode* t=new ListNode(ans[i]);
            node->next=t;
            node=t;
            i++;
        }
        return node1;
        
    }
};