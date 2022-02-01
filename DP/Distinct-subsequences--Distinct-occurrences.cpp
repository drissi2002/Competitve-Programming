int dp[8001][101];
    int subsequenceCount(string S, string T)
    {
       int n=S.size();
        int m=T.size();

        for (int i=0 ; i<=n ; i++)
        {
            for (int j=0 ; j<=m ; j++)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = 0;
                else
                {
                    if (S[i-1] == T[j-1])
                        dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }