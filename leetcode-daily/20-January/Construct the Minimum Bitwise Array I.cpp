class Solution {
public:
    int solve(int target){
        for(int i=1;i<target;i++){
            int curr = i | (i+1);
            if(curr==target)return i;
        }
        return -1;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> ans;
        for(auto x : nums){
            if(x==2){
                ans.push_back(-1);
                continue;
            }
            int idx = 1;
            while((x>>idx)&1){
                idx++;
            }
            idx--;
            x&=~(1<<idx);
            ans.push_back(x);
        }
        return ans;
    }
};