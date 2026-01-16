class Solution {
public:

    int solve(vector<int> &arr){

        int ans = 1;
        int i = 1,n=arr.size();
        while(i<n){
            int start = i;
            while(i<n && arr[i]-arr[i-1]==1){
                i++;
            }
            ans = max(ans,i-start+1);
            i++;
        }
        return ans;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int side = min(solve(hBars)+1,solve(vBars)+1);
        return side * side;
    }
};
