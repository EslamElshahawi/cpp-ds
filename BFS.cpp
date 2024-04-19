#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5, OO = 0x3f3f3f3f;

int n, m , u, v;

vector<int> adj[N];
int dis[N];


void BFS(int src){
    dis[src] = 0;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int f = q.front();
        q.pop();

        for(int v : adj[f]){
            if(dis[v] == OO){
                q.push(v);
                dis[v] = dis[f] + 1;
            }
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

    memset(dis, OO, sizeof dis);
    BFS(0);

    for(int u = 0; u < n; u++){
        cout << u << " " << dis[u] << "\n";
    }
}