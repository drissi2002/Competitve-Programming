using namespace std;

const int n=1000;
int no, e;
vector<pair<int,int>>edges;


int main()
{
    cin>>no>>e;
    for(int i=0;i<e;i++){
        int na, nb ;
        cin>>na>>nb;
        edges.push_back(make_pair(na,nb));
    }

    for(int i=0;i<e;i++){
            cout<<"("<<edges[i].first<<" , "<<edges[i].second<<")"<< " | ";
    }

    return 0;
}