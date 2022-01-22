#include <bits/stdc++.h>
//repsentation d'une graphe de N noued


   

 using namespace std;

const int n=1000;
int mat[n][n];
int no, e;

int main()
{
    cout<<"donnez les nombres des noueds et edges \n" ;
    cin>>no>>e;
    memset(mat,0,sizeof(mat));
    for(int i=0;i<e;i++){
        int nA ,nB;
        cin>>nA>>nB;
        mat[nA][nB]=1;
    }

    for(int i=0;i<no;i++)
        {
        for(int j=0;j<no;j++)
            {
                cout<<mat[i][j]<<" " ;
        }
        cout<<endl;
    }
    return 0;
} 
