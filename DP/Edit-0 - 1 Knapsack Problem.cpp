#include <bits/stdc++.h>
using namespace std;


int knapSack(int W, int wt[], int val[], int N)
    {
        int dp[1001][1001];

        for (int i=0; i<=N ; i++)
        {
            for (int j=0; j<=W ; j++)
            {
                // base case
                if (i==0 || j==0)
                    dp[i][j] = 0;
                else
                {
                    if (wt[i-1]<=j)
                        dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][W];
    }

