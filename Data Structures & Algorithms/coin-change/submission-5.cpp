class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n+1, vector<int>(amount+1, 1e9));
        for(int i=0; i<=n; i++){
            t[i][0] = 0;
        }
        for(int i=n-1; i>=0; i--){
            for(int a=1; a<=amount; a++){
                t[i][a] = t[i+1][a];
                if(a>=coins[i]){
                    t[i][a] = min(1 + t[i][a-coins[i]], t[i][a]);
                }
            }
        }
        return t[0][amount]==1e9 ? -1 : t[0][amount];
    }
};
