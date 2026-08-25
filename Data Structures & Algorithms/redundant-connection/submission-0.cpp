class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y){
        int rootA = find(x);
        int rootB = find(y);
        if(rootA == rootB) return;
        if(rank[rootA]<rank[rootB]){
            parent[rootA] = rootB;
        }
        else if(rank[rootA]>rank[rootB]){
            parent[rootB] = rootA;
        }
        else{
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.assign(n+1, 0);
        for(int i=1; i<n+1; i++){
            parent[i] = i;
        }
        for(auto & edge: edges){
            int u = edge[0];
            int v = edge[1];
            if(find(u)==find(v)) return {u,v};
            unite(u,v);
        }
        return {};
    }
};
