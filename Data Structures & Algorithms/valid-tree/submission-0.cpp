class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<bool>& vis){
        if(vis[node]) return;
        vis[node] = true;
        for(int neighbor : graph[node]) dfs(graph, neighbor, vis);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(graph, 0, vis);
        for(int i=0; i<n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
