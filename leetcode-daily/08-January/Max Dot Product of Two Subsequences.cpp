//Memoization
class Solution {
public:
    int solve(int i, int j, vector<int>& a, vector<int>& b,
              vector<vector<int>>& dp) {

        if (i < 0 || j < 0) return INT_MIN;
        if (dp[i][j] != INT_MAX) return dp[i][j];

        int take = a[i] * b[j];

        return dp[i][j] = max({
            take + max(0, solve(i - 1, j - 1, a, b, dp)),
            solve(i - 1, j, a, b, dp),
            solve(i, j - 1, a, b, dp)
        });
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        return solve(n - 1, m - 1, nums1, nums2, dp);
    }
};


//Tabulation
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int take = nums1[i - 1] * nums2[j - 1];
                dp[i][j] = max({
                    take + max(0, dp[i - 1][j - 1]),
                    dp[i - 1][j],
                    dp[i][j - 1]
                });
            }
        }
        return dp[n][m];
    }
};


//Space Optimization
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
        vector<int> prev(m + 1, INT_MIN), curr(m + 1, INT_MIN);

        for (int i = 1; i <= n; i++) {
            fill(curr.begin(), curr.end(), INT_MIN);

            for (int j = 1; j <= m; j++) {
                int take = nums1[i - 1] * nums2[j - 1];
                curr[j] = max({
                    take + max(0, prev[j - 1]),
                    prev[j],
                    curr[j - 1]
                });
            }
            prev.swap(curr);
        }
        return prev[m];
    }
};
