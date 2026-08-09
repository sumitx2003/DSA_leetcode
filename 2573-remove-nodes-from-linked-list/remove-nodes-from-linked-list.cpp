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
    ListNode* removeNodes(ListNode* head) {
       stack<ListNode*>st;
       ListNode* temp=head;
       while(temp!=NULL){
           if(st.empty()){
               st.push(temp);
           }
           else {
              if(st.top()->val>=temp->val){
                  st.push(temp);
              }
              else{
                  while(!st.empty() && st.top()->val<temp->val){
                     st.top();
                     st.pop();
                  }
                  st.push(temp);
              }
           }
           temp=temp->next;
       }
         ListNode* first=head;
       if(!st.empty()){
           first=st.top();
           st.pop();
       }
       first->next=NULL;
       while(!st.empty()){
            ListNode* temp=st.top();
            st.pop();
            temp->next=first;
            first=temp;
       }
       return first;
    }
};