# include <cstring>
class Solution {
public:
    int t[11][10001];
    int solve(int i, int amount, vector<int>& coins){
        int n = coins.size();
        if(i==n) return 1e9;
        if(amount==0) return 0;
        if(t[i][amount]!= -1) return t[i][amount];
        if(amount<coins[i]) return t[i][amount] = solve(i+1, amount, coins);
        int keep = 1 + solve(i, amount-coins[i], coins);
        int miss = solve(i+1, amount, coins);
        return t[i][amount] = min(keep, miss);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));
        int ans = solve(0, amount, coins);
        return ans>=1e9? -1: ans;
    }
};
