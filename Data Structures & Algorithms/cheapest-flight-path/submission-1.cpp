class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int inf = INT_MAX;
        vector<int> dist(n,inf);
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : flights){
            adj[e[0]].push_back({e[1], e[2]});
        }

        queue<tuple<int,int,int>> q;
        dist[src] = 0;
        q.emplace(src, 0, 0);

        while (!q.empty()){
            auto [node, d, stops] = q.front();
            //cout << node << " " << d << " "<< stops << endl;
            q.pop(); 
            
            for (auto& dest : adj[node]){
                if (d+dest.second < dist[dest.first] && stops <= k){
                    dist[dest.first] = d+dest.second;
                    q.emplace(dest.first, d+dest.second, stops+1);
                }
            }
        }

        return dist[dst] == inf ? -1 : dist[dst];
    }
};
