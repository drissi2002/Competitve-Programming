using namespace std;

const int n=1000;
int no, e;
vector<int>graph[n];


int main()
{
    cin>>no>>e;
    for(int i=0;i<e;i++){
        int na, nb ;
        cin>>na>>nb;
        graph[na].push_back(nb);
    }

    for(int i=0;i<no;i++){
        cout<<"liste des adjacents du noued "<<i<<":\n";
        for(int j=0 ;j<graph[i].size();j++){

            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}