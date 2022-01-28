#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];

int equalPartition(int N, int arr[])
    {
        int total = 0;
        for (int i=0 ; i<N ; i++)
            total+= arr[i];

        if (total %2 != 0)
            return 0;

        for (int i=0 ; i<=N ; i++)
        {
            for (int j=0 ; j<=total ; j++)
            {
                if (i == 0)
                {
                    if (j == total/2)
                        dp[i][i] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                {
                    if (j-arr[i-1]>=total/2)
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][total];
    }
    int main(){
        return 0;
    }

