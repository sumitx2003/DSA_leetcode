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
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)return 0;

        vector<int>vec;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int N=q.size();

            while(N--){
                TreeNode* node=q.front();
                q.pop();

                vec.push_back(node->val);

                if(node->left)q.push(node->left);

                if(node->right)q.push(node->right);

            }
        }
        sort(vec.begin(),vec.end());

        int ans=INT_MAX;

        for(int i=0;i<vec.size()-1;i++){
            if(ans>abs(vec[i]-vec[i+1])){
                ans=abs(vec[i]-vec[i+1]);
            }
        }
        return ans;
    }
};