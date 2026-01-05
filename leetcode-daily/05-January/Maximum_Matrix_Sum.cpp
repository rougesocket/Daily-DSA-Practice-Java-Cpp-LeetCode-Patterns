class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negativeCount = 0;
        long long minAbsValue = LLONG_MAX;

        for (const auto& row : matrix) {
            for (int value : row) {
                if (value < 0) {
                    negativeCount++;
                }
                long long absVal = llabs(value);
                minAbsValue = min(minAbsValue, absVal);
                totalSum += absVal;
            }
        }

        if (negativeCount % 2 == 0) {
            return totalSum;
        }

        return totalSum - 2 * minAbsValue;
    }
};
