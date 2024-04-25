class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>&graph, vector<int>&color){
        if(parent == -1 || color[parent] == 2){
            color[node] = 1;
        }
        else{
            color[node] = 2;
        }
        for(auto v : graph[node]){
            if(color[v] == -1){
                if(dfs(v, node, graph, color) == false) return false;
            }
            else if(color[v] == color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1 && dfs(i, -1, graph, color) == false) return false;
        }
        return true;
    }
};