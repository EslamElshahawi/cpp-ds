#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int N = 10e5, M = 20e5;
vector<int> adj[N];
bool vis[N];
stack<int> stck;
void DFS(int u){
    if(vis[u]) return;
    vis[u] = true;

    for(int v : adj[u]){
        DFS(v);
        cout << v;
    }
}

void DFS2(int u){
    stck.push(u);
    vis[u] = true;

     while(!stck.empty()){
        int s = stck.top();
        stck.pop();

        for(int v: adj[s]){
            if(!vis[v]){
                vis[v] = true;
                stck.push(v);
                cout << v << " " << vis[v];
            }
        }
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

    DFS2(0);
}