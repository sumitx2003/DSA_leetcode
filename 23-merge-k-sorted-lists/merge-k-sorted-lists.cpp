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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
          for(int i=0;i<lists.size();i++){
                if(lists[i]!=NULL){
                    int x=lists[i]->val;
                    pq.push({x,lists[i]});
                }     
                
          }
          if(pq.empty())return NULL;

          ListNode* temp=new ListNode(pq.top().first);
          ListNode* node=pq.top().second;
          pq.pop();
          if(node->next)pq.push({node->next->val,node->next});
          ListNode* curr=temp;
          while(!pq.empty()){
               ListNode* node =pq.top().second;
               int x=pq.top().first;
               pq.pop();
               temp->next=node;
               temp=temp->next;
               if(node->next)pq.push({node->next->val,node->next});
          }
          return curr;

    }
};