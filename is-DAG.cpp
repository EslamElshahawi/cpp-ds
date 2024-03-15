#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;

const int NOT_VISITED = 0, IN_PROGRESS = 1, VISITED = 2;

int n, m , u, v;

vector<int> adj[N];
bool vis[N];

bool isDAG(int u) {
    vis[u] = IN_PROGRESS;
    for(int v : adj[u]){
        if(vis[u] == NOT_VISITED)  { 
            if(!isDAG(v)) return false;
        }
        else if(vis[v] == IN_PROGRESS) return false;

    }
    vis[u] == VISITED;
    return true;
}

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
    }
    
    for(int i = 0; i < m; i++){
        if(vis[i] == NOT_VISITED){
            if (isDAG(i)){
                cout << "IS A DIRECTED ACYCLIC GRAPH";
                return 0;
            }
        }
    }
    cout << "CYCLIC";
    return 0;

}