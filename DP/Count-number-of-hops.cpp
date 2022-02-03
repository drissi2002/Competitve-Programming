long long dp[100001];
    long long countWays(int n)
    {
        for(int i=0;i<=n;i++)
        {  
            if(i==0){
                dp[i]=1;
                
            }
            else if(i>=3){
                dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000007;
            }
            else if(i>=2){
                dp[i]=(dp[i-1]+dp[i-2])%1000000007;
            }
            else {
                dp[i]=(dp[i-1])%1000000007;
            }
        }
        return dp[n];
    }