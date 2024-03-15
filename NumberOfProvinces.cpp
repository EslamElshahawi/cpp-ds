class Solution {
    void dfs(vector<vector<int>>& isConnected,vector<int> &visited,int i){
        visited[i] = 1;
        for(int j=0;j<isConnected[i].size();j++){
            if(isConnected[i][j] == 1 && !visited[j] && i != j){
                dfs(isConnected,visited,j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int count = 0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                count++;
            }
        }
        return count;
    }
};