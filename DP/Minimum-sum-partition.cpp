int minDifference(int arr[], int N)  {
	    
      int total = 0;
      
        for (int i=0 ; i<N ; i++)
            total+= arr[i];

        
        int dp[N+1][total+1];
       
        

        for (int i=0 ; i<=N ; i++)
        {
            for (int j=0 ; j<=total ; j++)
            {
                if (i == 0)
                {
                        dp[i][j] =abs(total-2*j) ;
                }
                else
                {
                    if (j-arr[i-1]>= 0)
                        dp[i][j] = min(dp[i-1][j],dp[i-1][j-arr[i-1]]);
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][total];
    } 