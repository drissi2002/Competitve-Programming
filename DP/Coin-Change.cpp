#include <bits/stdc++.h>
using namespace std;

long long int dp[1001][1001];

    long long int f(int S[], int n, int s) {

    if (dp[n][s]!=-1) {
        return dp[n][s];
    }

    if(s==0){
        dp[n][s]=1;

    }
    else if(n==0){
        dp[n][s]=0;

    }
    else{
            if(S[n-1]<=s){
                dp[n][s]=f(S,n-1,s)+f(S,n,s-S[n-1]);
            }
            else {
                dp[n][s]=f(S,n-1,s);
            }
    }
    return dp[n][s];

    }

    long long int count(int S[], int m, int n){
        memset(dp,-1,sizeof(dp));
        return f (S,m,n);
    }
