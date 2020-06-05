.
.
long getWays(int n, vector<long> c) {
sort(c.begin(),c.end());
    int l=c.size(),i,j;
    vector<vector<long>>dp(l+1,vector<long>(n+1));
    for(i=0;i<=l;i++)
        dp[i][0]=1;
    for(i=1;i<=l;i++){
        for(j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(j-c[i-1]>=0)
                dp[i][j]+=dp[i][j-c[i-1]];
        }
    }
    return dp[l][n];
}
.
.
.
