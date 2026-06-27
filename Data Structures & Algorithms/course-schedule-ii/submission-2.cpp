class Solution {
public:
    bool dfs(int prereqIndex, vector<vector<int>>& adj, vector<int>& visited, vector<int>& order){
        if (visited[prereqIndex] == 2) return true;
        if (visited[prereqIndex] == 1) return false;

        visited[prereqIndex] = 1;

        for (int courseIndex : adj[prereqIndex]){
            if (!dfs(courseIndex, adj, visited, order)){
                return false;
            }
        }
        order.push_back(prereqIndex);

        visited[prereqIndex] = 2;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> order;
        vector<vector<int>> adj(numCourses);
        
        for (auto& e : prerequisites){
            adj[e[0]].push_back(e[1]);
        }

        for (int courseIndex = 0; courseIndex < numCourses; courseIndex++){
            if (!dfs(courseIndex, adj, visited, order)){
                return {};
            }
        }

        return order;
    }
};
