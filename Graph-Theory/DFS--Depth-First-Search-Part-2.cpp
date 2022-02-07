#include <bits/stdc++.h>
using namespace std;

const int n=1e5;
vector<int>graph[n];
bool visted[n];
bool ancestor[n];

//Detect a cycle in directed Graph

int main()
{
    bool dfs(int node){

        visted[node]=true;
        ancestor[node]=true;

        for(int i=0 ;i<graph[node].size();i++)
            {
                int x =graph[node][i];
                if (visted[x] && ancestor[x]){
                        return true ;
                }
                else if( !visted[x] && dfs(x)){
                    return true ;
                }
            }
            ancestor[node]=false;
            return false;
    }
    return 0;
}
