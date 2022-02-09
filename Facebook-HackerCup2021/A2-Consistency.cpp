#include <bits/stdc++.h>
using namespace std;
#define Inf (long long)(999999)

    const int N=26 ;
    bool visited[26];
    int dist[26][26];

    vector<int> graph[N];

    void augmentedBFS( int node ){

        visited[node]= true ;
        queue<int>q;
        q.push(node);
        dist[node][node]=0;

        while(!q.empty()){

              int x = q.front();
              q.pop();

              for(int i=0 ; i< graph[x].size();i++){
                int nextChild = graph[x][i];
                if(! visited[nextChild]){

                    visited[nextChild]=true;
                    q.push(nextChild);
                    dist[node][nextChild]=1+dist[node][x];
                 }
               }
          }
     }

     int main() {

         freopen("a.text","r",stdin);
         freopen("a.out","w",stdout);

         string ch ,str ; // str : notre chaine de depart et
                          // ch  : la sous-chaine compose de 2 carc qui represente
                          //       le remplacement d'un carac par un autre
         int n , k ;
         int occurence[N];
         cin>>n;

         for(int cas=0;cas<n;cas++)
         {
             cin>>str;
             cin>>k;

             memset(occurence,0,sizeof(occurence));

             //remplir la table occurence des alphabet
             for(int i=0;i<str.size();i++){
                int posCrac = (int)(str[i]-'A');
                occurence[posCrac]++ ;
             }

             //initialisation de la matrice dist qui represente les couts
             // des distnce entre chaque carc de l'alphabet et toutes
             // les autres alphabets

             for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(i==j){
                        dist[i][j]=0;
                    }
                    else{
                        dist[i][j]=Inf;
                    }
                }
             }

             graph.clear();
             graph.resize(N);

             while(k--){

                cin>>ch;
                int posGraphParent = (int)(ch[0]-'A');
                int posGraphChild = (int)(ch[1]-'A');
                graph[posGraphParent].push_back(posGraphChild);
             }

             for (int i=0 ; i<26 ; i++)
                {
                    if (occurence[i]!=0)
                    {
                        memset(visited, 0, sizeof (visited));
                        augmentedBFS(i);
                    }
                }


            vector<int> carcDestination;

             for(int j=0 ;j<N;j++)
             {
                 bool isPossible = true;
                 for (int i=0 ; i<N ; i++)
                 {
                        if (occurence[i] == 0)
                            continue;
                        if (dist[i][j] == Inf)
                            {
                                isPossible = false;
                                break;
                            }
                 }
                 if (isPossible){
                    carcDestination.push_back(j);
                 }
             }
           int ans=INT_MAX;
           if (carcDestination.empty())
            {
                cout<<"Case #"<<cas<<": "<<-1<<'\n';
                continue;
            }
            for(auto a:carcDestination)
            {
                    int c=0;
                    for (int i=0 ; i<N ; i++)
                        {
                            if (occurence[i]==0)
                                continue;
                            c+=dist[i][a]*occurence[i];
                        }
                     ans=min(ans,c);
            }

            cout<<"Case #"<<cas<<": "<<ans<<'\n';
         }
         return 0;
     }

