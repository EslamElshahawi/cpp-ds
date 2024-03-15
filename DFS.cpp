#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;

int n, m , u, v;

vector<int> adj[N];
bool vis[N];

void DFS(int u) {
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            DFS(v);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int connectedComponents = 0;
    for (int u = 0; u < n; u++){
        if(!vis[u]){
            DFS(u);
            connectedComponents++;
        }
    }

    cout << connectedComponents;
}