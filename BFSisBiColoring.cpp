#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5, OO = 0x3f3f3f3f;
const int NOT_COLORED = 0, RED = 1, BLUE = 2;

int n, m , u, v;

vector<int> adj[N];
int color[N];

bool isBiColorable(int src){
    memset(color, NOT_COLORED, sizeof color);
    color[src] = RED;
    queue<int > q;
    q.push(src);
    

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(color[v] == NOT_COLORED){
                color[v] = (color[u] == RED ? BLUE : RED);
                q.push(v);
            }
            else if (color[u] == color[v]) return false;
        }
    }
    
    
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (isBiColorable(0) ? "YES" : "NO");

}