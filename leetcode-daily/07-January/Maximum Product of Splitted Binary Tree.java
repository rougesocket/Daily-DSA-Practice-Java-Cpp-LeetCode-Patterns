class Solution {

    long ans = 0;
    long mod = (long)1e9 + 7;

    long getTotalSum(TreeNode root) {
        if (root == null) return 0;
        return root.val + getTotalSum(root.left) + getTotalSum(root.right);
    }

    long dfs(TreeNode root, long total) {
        if (root == null) return 0;

        long left = dfs(root.left, total);
        long right = dfs(root.right, total);

        long subTreeSum = left + right + root.val;
        ans = Math.max(ans, subTreeSum * (total - subTreeSum));

        return subTreeSum;
    }

    public int maxProduct(TreeNode root) {
        long total = getTotalSum(root);
        dfs(root, total);
        return (int)(ans % mod);
    }
}
