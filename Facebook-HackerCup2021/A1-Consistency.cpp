#include <iostream>

using namespace std;

/*
 pour transformer le string en totalité des voyelles :
      -- F1 = 2*(NbreTotaleDesVoyelles() - OccurenceMaxDuVoyelles())+ NbreTotaleDesConsonnes()
 pour transformer le string en totalité des consonnes :
      -- F2 = 2*(NbreTotaleDesConsonnes() - OccurenceMaxDuConsonnes())+NbreTotaleDesVoyelles()
 pour transformer la chaine indepedement :
      -- MIN(F1 ,F2)
*/

bool isVoyelle(char c)
{
    return (c=='A'||c=='E'||c=='I'||c=='O'||c=='U') ;
}


int main()
{
    freopen("a.text","r",stdin);
    freopen("a.out","w",stdout);

    int n;
    string ch ;
    cin>>n;

    for(int cas=0;cas<n;cas++)
    {
        cin>>ch;
        int maxV=0 ,maxC=0,TV=0,TC=0 ;
        int tab[26];
        memset(tab,0,sizeof(tab));
        for(int i=0;i<ch.size();i++){
            tab[ch[i]-'A']++
        }

        for(int i=0;i<26;i++){
            if(isVoyelle(i+'A')){
                maxV = max(maxV,tab[i]);
                TV+=tab[i];
            }
            else
            {
                maxC = max(maxC+tab[i]);
                TC+=tab[i];

            }
        }
        cout<<"Case #"<<cas<<" : "<<min((TV-maxV)*2+TC ,(TC-maxC)*2+TV )<<'\n':
    }




    return 0;
}
