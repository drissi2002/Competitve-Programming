long long dp [1001][1001]; 
    long long f(int i ,int j, int arr[], int n){
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>j){
            dp[i][j]=0;
        }
        else{
            dp[i][j]=max(arr[i]+min(f(i+2,j,arr,n),f(i+1,j-1,arr,n)), arr[j]+min(f(i,j-2,arr,n),f(i+1,j-1,arr,n)));
        }
        
        return dp[i][j];
    }
    long long maximumAmount(int arr[], int n){
        memset(dp, -1, sizeof(dp));
        return f(0,n-1,arr,n);
    }