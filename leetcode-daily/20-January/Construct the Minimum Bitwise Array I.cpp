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
        for(auto x : nums)ans.push_back(solve(x));
        return ans;
    }
};