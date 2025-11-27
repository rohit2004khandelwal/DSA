class Solution {
public:
    void dfsHelper(unordered_map<int, vector<int>> &adjList, int u, vector<bool> &visited){
        visited[u] = true;

        for(auto v:adjList[u]){
            if(!visited[v]){
                dfsHelper(adjList, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> adjList;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int count = 0;
        for(int src=0; src<n; src++){
            if(!visited[src]){
                count++;
                dfsHelper(adjList, src, visited);
            }
        }
        return count;
    }
};