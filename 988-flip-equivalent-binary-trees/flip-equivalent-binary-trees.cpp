/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*>q;
        queue<TreeNode*>q1;
        q1.push(root2);
        q.push(root1);

        if(root1==NULL && root2==NULL)return true;

        if((root1==NULL && root2!=NULL) || (root2==NULL && root1!=NULL))return false;

        if((root1!=NULL && root2!=NULL)&&(root1->val!=root2->val))return false;
        
        while(!q.empty()){
            int N=q.size();
            string str="";
            string str1="";
            unordered_map<int,int>mp;
            unordered_map<int,int>mp1;
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                TreeNode* node1=q1.front();
                q1.pop();

                if(node->left){
                    q.push(node->left);
                    str+=to_string(node->left->val);
                    mp[node->left->val]=node->val;

                }
                if(node->right){
                    q.push(node->right);
                   str+=to_string(node->right->val);
                   mp[node->right->val]=node->val;
                }

                if(node1->left){
                    q1.push(node1->left);
                    str1+=to_string(node1->left->val);
                    mp1[node1->left->val]=node1->val;

                }
                if(node1->right){
                    q1.push(node1->right);
                    str1+=to_string(node1->right->val);
                    mp1[node1->right->val]=node1->val;
                }
            }
            sort(str.begin(),str.end());
            sort(str1.begin(),str1.end());
            if(str!=str1)return false;

            for(auto &it:mp){
                if(it.second!=mp1[it.first])return false;
            }
        }
        return true;
    }
};