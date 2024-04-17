#include <iostream>
#include <vector>

using namespace std;

const int N = 10e5, M = 20e5;
vector<int> adj[N];
bool vis[N];
void DFS(int u){
    if(vis[u]) return;
    vis[u] = true;

    for(int v: adj[u]){
        DFS(v);
        cout << v;
    }
}

int main(){
    int n, m, u ,v;


    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(0);
}