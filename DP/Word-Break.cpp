#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

    int f(int i,string line , vector<string> & B,int l,int n){

        if (dp[i][l] != -1)
        return dp[n][l];

        if (l==0){
            dp[i][l]=1;
        }
        else if( n==0){
            dp[i][l]=0;
        }
        else{

            string ch = line.substr(0,l);
            int k = ch.rfind(B[n-1]);

            if(k!=-1 && ch.size()==k+B[i].size()){
                dp[i][l]=f(n,ch,B,l-B[i-1].size(),n)+ f(i-1,ch,B,l,n);
            }
            else{
                dp[i][l]=f(i-1,ch,B,l,n);
            }

        }
        return dp[n][l];

    }
    int wordBreak(string A, vector<string> &B) {

        memset(dp, -1, sizeof(dp));

        if ( f( B.size(),A, B,A.size(),B.size())!=0) {
            return 1;
        }
        else{
            return 0;
        }
    }
