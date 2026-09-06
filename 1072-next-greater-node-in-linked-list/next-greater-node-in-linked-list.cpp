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
    vector<int> nextLargerNodes(ListNode* head) {
        int count=0;
        ListNode* curr=head;
        while(curr){
            count++;
            curr=curr->next;
        }
        int i=0;
        vector<int>vec(count,0);
        ListNode* temp=head;
        stack<pair<int,int>>st;
        while(temp){
           if(st.empty()){
              st.push({temp->val,i});
              temp=temp->next;
              i++;
           }
           else if(st.top().first>temp->val){
                st.push({temp->val,i});
                temp=temp->next;
                i++;
           }
           else{
               while(!st.empty() && temp!=NULL && st.top().first<temp->val){
                    int x=st.top().first;
                    int idx=st.top().second;
                    vec[idx]=temp->val;
                    st.pop();

               }
               if(temp!=NULL){
                  st.push({temp->val,i});
                  i++;
               }
               temp=temp->next;
             
           }

        }
        return vec;
    }
};