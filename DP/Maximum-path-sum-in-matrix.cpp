 int dp[1001][1001];
    int maximumPath(int N, vector<vector<int>> tab)
    {
        memset(dp, -1, sizeof(dp));
        for (int n=0 ; n<N ; n++)
        {
            for (int m=0 ; m<N ; m++)
            {
                if (n == 0)
                    dp[n][m] = tab[n][m];
                else if (m == 0)
                    dp[n][m] = tab[n][m] + max(dp[n-1][m], dp[n-1][m+1]);
                else if (m == N-1)
                    dp[n][m] = tab[n][m] + max(dp[n-1][m-1], dp[n-1][m]);
                else
                    dp[n][m] = tab[n][m] + max(dp[n-1][m-1], max(dp[n-1][m], dp[n-1][m+1]));
            }
        }

        int m=0;
        for (int i=0 ; i<N ; i++)
        {
            int res = dp[N-1][i];
            m = max(m, res);
        }


        return m;
    }