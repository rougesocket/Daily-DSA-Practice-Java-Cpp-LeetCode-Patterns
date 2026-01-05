class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long totalSum = 0;
        long negativeCount = 0;
        long minAbsValue = Long.MAX_VALUE;

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                int value = matrix[i][j];
                if (value < 0) negativeCount++;
                long absVal = Math.abs(value);
                minAbsValue = Math.min(minAbsValue, absVal);
                totalSum += absVal;
            }
        }

        if (negativeCount % 2 == 0) {
            return totalSum;
        }

        return totalSum - 2 * minAbsValue;
    }
}
