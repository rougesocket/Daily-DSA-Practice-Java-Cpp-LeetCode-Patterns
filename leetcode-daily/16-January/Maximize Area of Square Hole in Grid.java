class Solution {

    public int solve(int arr[]){
        int ans = 1,i=1;
        while(i<arr.length){
            int start = i;
            while(i<arr.length && arr[i]-arr[i-1]==1)i++;
            ans = Math.max(ans,i-start+1);
            i++;
        }
        return ans;
    }

    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        
        Arrays.sort(hBars);
        Arrays.sort(vBars);

        int side = Math.min(solve(hBars)+1,solve(vBars)+1);
        return side*side;
    }
}
