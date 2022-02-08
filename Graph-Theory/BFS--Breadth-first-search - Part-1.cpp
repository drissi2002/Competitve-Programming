#include <bits/stdc++.h>
using namespace std;

  

    const int N =1e5;
    bool visited[N];
    vector<int> graph[N];

    void BFS( int node ){

        visited[node]= true ;
        queue<int>q;
        q.push(node);

        while(!q.empty()){
              int x = q.front();
              q.pop();
              for(int i=0 ; i< graph[x].size();i++){
                int nextChild = graph[x][i];
                if(! visited[nextChild]){
                    visited[nextChild]=true;
                    q.push(nextChild);
                }
            }
        }
   }

