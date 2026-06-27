class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        if (visited[node] == 2) return true;
        if (visited[node] == 1) return false;

        visited[node] = 1;

        for (int n : adj[node]){
            if (!dfs(n, adj, visited)){
                return false;
            }
        }

        visited[node] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& e : prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < numCourses; i++){
            if (!dfs(i, adj, visited)){
                return false;
            }
        }

        return true;
    }
};
