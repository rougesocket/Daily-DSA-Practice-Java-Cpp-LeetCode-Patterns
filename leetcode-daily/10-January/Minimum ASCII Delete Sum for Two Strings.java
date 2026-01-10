//Memoization
class Solution {

    public int lcs(int i,int j,String s1,String s2,int dp[][]){

        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1.charAt(i)==s2.charAt(j))return dp[i][j]=s1.charAt(i)+lcs(i-1,j-1,s1,s2,dp);
        return dp[i][j]=Math.max(lcs(i,j-1,s1,s2,dp),lcs(i-1,j,s1,s2,dp));
    }
    public int minimumDeleteSum(String s1, String s2) {
        
        int n = s1.length(),m=s2.length();

        int[][] dp = new int[n][m];
        for(int []d : dp){
            Arrays.fill(d,-1);
        }
        int total = 0;
        for(char ch : s1.toCharArray())total+=ch;
        for(char ch : s2.toCharArray())total+=ch;

        return total-2*lcs(n-1,m-1,s1,s2,dp);
    }
}
//tabulation
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        
        int n = s1.length(),m=s2.length();

        int[][] dp = new int[n+1][m+1];
        for(int []d : dp){
            Arrays.fill(d,0);
        }
        int total = 0;
        for(char ch : s1.toCharArray())total+=ch;
        for(char ch : s2.toCharArray())total+=ch;


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1.charAt(i-1)==s2.charAt(j-1))dp[i][j]=s1.charAt(i-1)+dp[i-1][j-1];
                else dp[i][j]=Math.max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return total-2*dp[n][m];
    }
}
//Space optimization

class Solution {
   public int minimumDeleteSum(String s1, String s2) {
        
        int n = s1.length(),m=s2.length();
        int[] prev = new int[m+1];
        int[] curr = new int[m+1];
        int total = 0;
        for(char ch : s1.toCharArray())total+=ch;
        for(char ch : s2.toCharArray())total+=ch;


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1.charAt(i-1)==s2.charAt(j-1))curr[j]=s1.charAt(i-1)+prev[j-1];
                else curr[j]=Math.max(curr[j-1],prev[j]);
            }

            int[] temp = prev;
            prev=curr;
            curr=temp;
        }
        return total-2*prev[m];
    }
}