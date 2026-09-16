class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 1e9;
        vector<int> dist(n,INF);
        dist[src] = 0;
        for(int i=0; i<=k; i++){
            vector<int> temp = dist;
            for(auto & flight: flights){
                int from = flight[0];
                int to = flight[1];
                int wt = flight[2];
                if(dist[from]==INF) continue;
                temp[to] = min(temp[to], dist[from] + wt);
            }
            dist = temp;
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
};
