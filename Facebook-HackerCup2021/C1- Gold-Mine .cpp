#include <bits/stdc++.h>
using namespace std;

const int N=55;
    vector<vector<int>> graph;
    vector<int> coins ;
    int nbreCas,n,m=0 ;
    bool visted[N];
    int maximum =0;

    void dfs(int parent){
        visted[parent]=true;

        maximum= max(maximum,coins[parent]);
        for(int i=0 ;i<graph[parent].size();i++){
                if(!visited[i]){
                        coins[i]+=coins[parent];
                        dfs(i);
                }
        }
        return ;
    }

int main(){

    freopen("a.txt","r",stdin);
    freopen("a.out","w",stdout);

    cin>>nbreCas;
    for(int cas =1 ;cas <= nbreCas ;cas++)
    {
        cin>>n;

        //vider a chaque fois le graphe pour le reutiliser

        graph.clear();
        graph.resize(n+5);
        coins.clear();
        coins.resize(n+5);

        //remplir le tableau coins
        for(int i=0 ;i<n;i++){
            cin>>coins[i];
        }

        //representation de la graphe desirée*
        for(int j=0);j<n-1;j++){
            int parent , child ;
            cin>>parent>>child ;
            graph[parent].push_back(child);
            // puisque il s'agit du indirected graph
            graph[child].push_back(parent);
        }

        //rensiliser tableau visited
        memset(visited,0,sizeof(visited));
        // puisque la graph commence par le 1
        visited[1]=true;
        vector<int> MaxSousGraph ;

        //enregister le maximum du coins collectée pour chaque sous-graphe
        for(int i=0 ;i< graph[1].size();i++){
            maximum =0 ;
            dfs(i);
            MaxSousGraph.push_back(maximum);
        }

        //en va choisir les 2 Plus grandes valeurs dy MaxSousGraph
        //Trier le tableau MaxSousGraph
        sort(MaxSousGraph.begin(),MaxSousGraph().end(),greater<int>());
        int entreeCave = coins[1];

        for(int k=0 ;k< min(2,(int)entreeCave.size());k++){
            entreeCave+=MaxSousGraph[k];
        }

        cout<<"Case #"<<cas<<" : "<<entreeCave<<'\n' ;
    }
  return 0;
}

