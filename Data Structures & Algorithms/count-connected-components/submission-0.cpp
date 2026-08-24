class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;
    void dfs(int node){
        vis[node] = true;
        for(int next : graph[node]){
            if(!vis[next])
                dfs(next);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vis.assign(n, false);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};
