class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        for (int i = 0; i < words.size(); i++){
            for (char c : words[i]){
                adj[c] = {};
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size()-1; i++){
            int x = 0, y = 0, l1 = words[i].size(), l2 = words[i+1].size();
            while (x < l1 && y < l2 && words[i][x] == words[i+1][y]){
                x++;
                y++;
            }
            if (x < l1 && y < l2){
                adj[words[i][x]].push_back(words[i+1][y]);
                indegree[words[i+1][y]]++;
            }
            else if (l1 > l2) return "";
        }

        string order = "";
        queue<char> q;
        for (auto i : indegree){
            if (i.second == 0){
                q.push(i.first);
            }
        }

        while (!q.empty()){
            char k = q.front();
            order += k;
            q.pop();
            for (char c : adj[k]){
                indegree[c]--;
                if (indegree[c] == 0){
                    q.push(c);
                }
            }
        }

        if (order.size() == indegree.size()) return order;
        return "";  
    }
};
