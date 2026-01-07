class Solution {
public:
    long long ans = 0;
    const long long mod = 1e9 + 7;

    long long getTotal(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotal(root->left) + getTotal(root->right);
    }

    long long dfs(TreeNode* root, long long total) {
        if (!root) return 0;

        long long left = dfs(root->left, total);
        long long right = dfs(root->right, total);

        long long subTreeSum = left + right + root->val;
        ans = max(ans, subTreeSum * (total - subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        long long total = getTotal(root);
        dfs(root, total);
        return ans % mod;
    }
};
