#include <bits/stdc++.h>
using namespace std;

// dp[..] for memorizing the results of every calculation
long long int dp[1001];

class Fibonacci {
  public:
    long long int nthFibonacci(long long int n){
        if (dp[n]!=0){
            return dp[n];
        }
        if (n<=2) {
            dp[n]=1 ;
        }
        else {
            dp[n]=((nthFibonacci(n-1)+nthFibonacci(n-2)) % 1000000007);

        }
        return dp[n];
    }
};

