class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>t (n+1, vector<int>(amount+1, 0));
        for(int i=0; i<=n; i++){
            t[i][0] = 1;
        }
        for(int i=n-1; i>=0; i--){
            for(int a=1; a<=amount; a++){
                t[i][a] = t[i+1][a];
                if(a>=coins[i])
                    t[i][a] += t[i][a-coins[i]];
            }
        }
        return t[0][amount];
    }
};