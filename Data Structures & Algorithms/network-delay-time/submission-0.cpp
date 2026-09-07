class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto i:times){
            int u = i[0];
            int v = i[1];
            int t = i[2];
            graph[u].push_back({v, t});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
        dist[k] = 0;
        q.push({0, k});
        while(!q.empty()){
            auto [time, node] = q.top();
            q.pop();
            if(time > dist[node]) continue;
            for(auto [next, wt]: graph[node]){
                int newTime = time+wt;
                if(newTime < dist[next]){
                    dist[next] = newTime;
                    q.push({newTime, next});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
