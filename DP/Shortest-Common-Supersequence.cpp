    int dp[101][101];
    int f(string x, string y, int m, int n)
    {
         if (dp[m][n] != -1){
             return dp[m][n];
         }
         if (m == 0){
        dp[m][n] = n;
             
         }
         else if (n == 0){
             dp[m][n] = m;
             
         }
         else
         {
             if (x[m-1] == y[n-1]){
                 dp[m][n] = 1 + f(x,y,m-1,n-1);
                 
             }
             else
             {
                 dp[m][n] = 1 + min(f(x,y,m-1,n), f(x,y,m,n-1));
             }
         }
         return dp[m][n];
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n){
        memset(dp,-1,sizeof(dp));
        return f(X,Y,m,n);
    }