class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t){

        int n = b.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long width = min(t[i][0],t[j][0])-max(b[i][0],b[j][0]);
                long long height = min(t[i][1],t[j][1])-max(b[i][1],b[j][1]);
                ans = max(ans,min(width,height));
            }
        }
        return ans*ans*1LL;
    }
};