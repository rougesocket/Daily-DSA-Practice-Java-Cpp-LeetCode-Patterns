class Solution {

    public int solve(int target){
        for(int i=1;i<target;i++){
            int curr = i | (i+1);
            if(target==curr)return i;
        }
        return -1;
    }
    public int[] minBitwiseArray(List<Integer> nums) {

        int n = nums.size(),i=0;
        int[] ans = new int[n];

        for(int x : nums){
            ans[i++]=solve(x);
        }
        
        return ans;
    }
}