class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long int> > mxd(n,vector<long long int> (m,0)),mnd(n,vector<long long int> (m,0));
        mxd[0][0]=grid[0][0];
        mnd[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            mxd[i][0]=mxd[i-1][0]*grid[i][0];
            mnd[i][0]=mnd[i-1][0]*grid[i][0];
        }
        for(int i=1;i<m;i++){
            mxd[0][i]=mxd[0][i-1]*grid[0][i];
            mnd[0][i]=mnd[0][i-1]*grid[0][i];
        }

        long long int ans = -1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){

                mxd[i][j]=max({mxd[i-1][j],mxd[i][j-1],
                                 mnd[i-1][j],mnd[i][j-1]})*grid[i][j];
                mnd[i][j]=min({mxd[i-1][j],mxd[i][j-1],
                                 mnd[i-1][j],mnd[i][j-1]})*grid[i][j];
            }
        }
        ans = max({ans,mxd[n-1][m-1],mnd[n-1][m-1]});


        int mod = 1e9+7;
        if(ans<0)return -1;
        return ans%mod;
    }
};