class Solution {
public:
    vector<int> ans;

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;

        ans.push_back(root->val);

        int left = dfs(root->left);
        int right = dfs(root->right);

        left = max(0, left);
        right = max(0, right);

        int currsum = left + right + root->val;

        ans.push_back(currsum);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);

        int maxs = INT_MIN;

        for (int x : ans)
            maxs = max(maxs, x);

        return maxs;
    }
};