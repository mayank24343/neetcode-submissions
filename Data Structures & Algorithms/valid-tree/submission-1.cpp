class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited,int parent){
        if (visited[node] == 2) return true;
        if (visited[node] == 1) return false;

        visited[node] = 1;

        for (int nghbr : adj[node]){
            if (nghbr == parent) continue;
            if (!dfs(nghbr, adj, visited, node)){
                return false;
            }
        }

        visited[node] = 2;

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        for (auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visited(n,0);
        if (!dfs(0, adj, visited, -1)){
            return false;
        }
        for (int i : visited){
            if (i != 2) return false;
        }

        return true;
    }
};
