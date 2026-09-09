class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> vis(n, false);
        minDist[0] = 0;
        int totalCost = 0;
        for(int i=0; i<n; i++){
            int curr = -1;
            for(int j=0; j<n; j++){
                if(!vis[j] && (curr==-1 || minDist[j]<minDist[curr])){
                    curr = j;
                }
            }
            vis[curr] = true;
            totalCost += minDist[curr];
            for(int j=0; j<n; j++){
                if(!vis[j]){
                    int cost = abs(points[curr][0]-points[j][0]) + abs(points[curr][1]-points[j][1]);
                    minDist[j] = min(minDist[j], cost);
                }
            }
        }
        return totalCost;
    }
};
