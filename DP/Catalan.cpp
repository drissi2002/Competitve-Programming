#include <bits/stdc++.h>
using namespace std;

int dp[101];
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n)
    {
        if (dp[n]!=0){
            return dp[n];
        }
        if (n==0){
             dp[n]=1;
        }
        else
            for(int i=0;i<n;i++){
                dp[n]+=findCatalan(i)*findCatalan(n-i-1);
            }

        return dp[n];  }
};

