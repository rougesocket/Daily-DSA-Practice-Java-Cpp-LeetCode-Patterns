class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        

        long side = 0L;
        for(int i=0;i<bottomLeft.length;i++){
            for(int j=i+1;j<bottomLeft.length;j++){
                long width = Math.min(topRight[i][0],topRight[j][0])-Math.max(bottomLeft[i][0],bottomLeft[j][0]);
                long height = Math.min(topRight[i][1],topRight[j][1])-Math.max(bottomLeft[i][1],bottomLeft[j][1]);
                side = Math.max(side,Math.min(width,height));
            }
        }
        return side*side*1L;
    }
}