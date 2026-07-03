/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if(root == NULL) return "";

        queue<TreeNode*> q;
        q.push(root);
        str += to_string(root->val);
        str += ",";

        while(!q.empty()){
            int N = q.size();
            while(N--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    str += to_string(node->left->val);
                    str += ",";
                }
                else{
                    str += "*,";
                }

                if(node->right){
                    q.push(node->right);
                    str += to_string(node->right->val);
                    str += ",";
                }
                else{
                    str += "*,";
                }
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.empty()) return NULL;

        queue<TreeNode*> q;

        int i = 0;
        string num = "";

        while(i < data.size() && data[i] != ','){
            num += data[i];
            i++;
        }

        TreeNode* root = new TreeNode(stoi(num));
        q.push(root);
        i++; // skip ','

        while(!q.empty() && i < data.size()){

            TreeNode* node = q.front();
            q.pop();

            TreeNode* lef = NULL;
            TreeNode* righ = NULL;

            // Left child
            if(data[i] == '*'){
                i++;
            }
            else{
                num = "";
                while(i < data.size() && data[i] != ','){
                    num += data[i];
                    i++;
                }
                lef = new TreeNode(stoi(num));
            }

            if(i < data.size() && data[i] == ',') i++;

            // Right child
            if(i < data.size() && data[i] == '*'){
                i++;
            }
            else if(i < data.size()){
                num = "";
                while(i < data.size() && data[i] != ','){
                    num += data[i];
                    i++;
                }
                righ = new TreeNode(stoi(num));
            }

            if(i < data.size() && data[i] == ',') i++;

            node->left = lef;
            node->right = righ;

            if(lef) q.push(lef);
            if(righ) q.push(righ);
        }

        return root;
    }
};