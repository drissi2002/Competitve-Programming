//Check if graph is connected -- path existence between two nodes
const int n=1e5;
vector<int>graph[n];
bool visted[n];
int main()
{
    void dfs(int node){
        visted[node]=true;
        for(int i=0 ;i<graph[node].size();i++){
            int x =graph[node][i];
            if (!visted[x]){
                dfs(x);
            }
        }
        return;
    }
    return 0;
    
    
