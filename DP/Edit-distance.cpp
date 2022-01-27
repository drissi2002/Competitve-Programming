#include <bits/stdc++.h>
using namespace std;


int editDistance(string s, string t) {
        int dp[101][101];
        int x=s.size();
        int y=t.size();
        for (int i=0 ; i<=x ; i++)
        {
            for (int j=0 ; j<=y ; j++)
            {
                if (i==0)
                    dp[i][j] = j;
                else if (j==0)
                    dp[i][j] = i;
                else
                {
                    if (s[i-1] == t[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }

        }
        return dp[x][y];
    }

int main()
{
    string ch1;
    string ch2 ;
    int dp[101][101] ;
    memset(dp,-1,sizeof(dp));
    cin>>ch1>>ch2;
    cout<<"le nombre d'operation necessaire est :" ;
    int a=editDistance(ch1,ch2);
    cout<<a;
   return 0;
}
