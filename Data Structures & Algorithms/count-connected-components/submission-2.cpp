class DisjointSet {
    vector<int> parent;
    int comp;
public:

    DisjointSet(int n) {
        parent.resize(n,0);
        iota(parent.begin(), parent.end(), 0);
        comp = n;
    }

    int getComponents(){
        return comp;
    }

    int findParent(int x){
        if (x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    bool setUnion(int x, int y){
        int parent_x, parent_y;
        parent_x = findParent(x);
        parent_y = findParent(y);

        if (parent_x == parent_y) return false;
        
        //cout << x << " " << y << endl;
        parent[parent_y] = parent_x;
        comp --;
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet DS = DisjointSet(n);
        for (auto& e : edges){
            DS.setUnion(e[0], e[1]);
        }

        return DS.getComponents();

    }
};
