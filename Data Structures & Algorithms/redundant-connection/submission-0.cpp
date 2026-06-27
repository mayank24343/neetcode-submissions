class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;
    int comp;

public:
    DisjointSet(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        cout << endl;
        size.resize(n, 1);
        comp = n;
    }

    int findParent(int node){
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool areConnected(int x, int y){
        int parent_x = findParent(x), parent_y = findParent(y);
        return parent_x == parent_y;
    }

    bool setUnion(int x, int y){
        int parent_x = findParent(x), parent_y = findParent(y);
       
        if (parent_x == parent_y) return false;
        
        if (size[parent_x] > size[parent_y]){
            parent[parent_y] = parent_x;
            size[parent_x] += size[parent_y];
        }
        else{
            parent[parent_x] = parent_y;
            size[parent_y] += size[parent_x];
        }

        comp--;
        return true;
    }

    int getComponents(){
        return comp;
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet DSU = DisjointSet(n);

        for (auto& e : edges){
            if (!DSU.setUnion(e[0]-1, e[1]-1)){
                return e;
            }
        }

        return {};
        
    }
};
