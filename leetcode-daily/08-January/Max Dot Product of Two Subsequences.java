//Memoization
class Solution {

    int f(int i, int j, int[] a, int[] b, int[][] dp) {
        if (i < 0 || j < 0) return Integer.MIN_VALUE;

        if (dp[i][j] != Integer.MIN_VALUE) return dp[i][j];

        int prod = a[i] * b[j];

        return dp[i][j] = Math.max(
            prod + Math.max(0, f(i - 1, j - 1, a, b, dp)),
            Math.max(
                f(i, j - 1, a, b, dp),
                f(i - 1, j, a, b, dp)
            )
        );
    }

    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        int[][] dp = new int[n][m];
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }

        return f(n - 1, m - 1, nums1, nums2, dp);
    }
}

//Tabulation
class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {

        int n = nums1.length;
        int m = nums2.length;

        int[][] dp = new int[n + 1][m + 1];
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int prod = nums1[i - 1] * nums2[j - 1];

                dp[i][j] = Math.max(
                    prod + Math.max(0, dp[i - 1][j - 1]),
                    Math.max(dp[i - 1][j], dp[i][j - 1])
                );
            }
        }

        return dp[n][m];
    }
}

//Space Optimization
class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {

        int n = nums1.length;
        int m = nums2.length;

        int[] prev = new int[m + 1];
        int[] curr = new int[m + 1];

        Arrays.fill(prev, Integer.MIN_VALUE);

        for (int i = 1; i <= n; i++) {
            Arrays.fill(curr, Integer.MIN_VALUE);

            for (int j = 1; j <= m; j++) {
                int prod = nums1[i - 1] * nums2[j - 1];

                curr[j] = Math.max(
                    prod + Math.max(0, prev[j - 1]),
                    Math.max(prev[j], curr[j - 1])
                );
            }

            int[] temp = prev;
            prev = curr;
            curr = temp;
        }

        return prev[m];
    }
}
