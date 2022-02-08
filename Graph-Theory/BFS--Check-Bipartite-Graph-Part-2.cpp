#include <bits/stdc++.h>
using namespace std;


    const int N =1e5;
    bool visited[N];
    int color[N];
    queue<int>q;
    bool BfsBiparted( int V , vector<int>graph[]){



        memset(visited,false,sizeof(visited));
        memset(color,0,sizeof(color));



        for(int node=0;node<V;node++) //to explore the case of disconnected graph
        {
            if(!visited[node])
            {
                visited[node]=true;
                color[node]=1; //red
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
                            if(color[nextChild]==color[x]){
                                    return false ;
                            }
                            else if (color[nextChild]==0){
                                    if(color[x]==1){
                                        color[nextChild]=2; //blue
                                    }
                                    else{
                                        color[nextChild]=1; //red
                                    }
                            }
                       }
                }
            }
        }
        return true ;
    }

