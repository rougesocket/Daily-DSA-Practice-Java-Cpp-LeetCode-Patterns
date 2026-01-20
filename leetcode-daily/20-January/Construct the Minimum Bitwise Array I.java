class Solution {

    public int[] minBitwiseArray(List<Integer> nums) {

        int n = nums.size(),i=0;
        int[] ans = new int[n];

        for(int x : nums){
            if(x==2){
                ans[i++]=-1;
                continue;
            }
            int idx=1;
            while(((x>>idx)&1)==1){
                idx++;
            }
            idx--;
            x&=~(1<<idx);
            ans[i++]=x;
        }
        
        return ans;
    }
}