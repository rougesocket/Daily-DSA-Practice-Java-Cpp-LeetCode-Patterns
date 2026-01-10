//Memoization
class Solution {
public:

    int f(int i,int j,string &s1,string &s2,vector<vector<int> > &dp){

        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return s1[i]+f(i-1,j-1,s1,s2,dp);
        return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m=s2.size();
        int tot = 0;
        for(auto ch : s1)tot+=ch;
        for(auto ch : s2)tot+=ch;
        vector<vector<int> > dp(n,vector<int> (m,-1));
        return tot-2*f(s1.size()-1,s2.size()-1,s1,s2,dp);
    }
};

//Tabulation
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m=s2.size();
        int tot = 0;
        for(auto ch : s1)tot+=ch;
        for(auto ch : s2)tot+=ch;
        vector<vector<int> > dp(n+1,vector<int> (m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]= s1[i-1]+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return tot-2*dp[n][m];
    }
};


//Space Optimization
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m=s2.size();
        int tot = 0;
        for(auto ch : s1)tot+=ch;
        for(auto ch : s2)tot+=ch;
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])curr[j]= s1[i-1]+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return tot-2*prev[m];
    }
};