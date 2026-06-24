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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        queue<TreeNode*>q;
        int level=0;
        q.push(root);
        bool  leveladded=false;
        while(!q.empty()){
            int N=q.size();
            level++;
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(level==depth-1){
                    // if(node->left){
                        TreeNode* templ=node->left;
                        node->left=new TreeNode(val);
                        node->left->left=templ;
                    // }
                    // if(node->right){
                        TreeNode* tempr=node->right;
                        node->right=new TreeNode(val);
                        node->right->right=tempr;
                    // }
                    leveladded=true;
                }
                if(node->left)q.push(node->left);

                if(node->right)q.push(node->right);
            }
            if(leveladded==true)break;
        }
        return root;
    }
};