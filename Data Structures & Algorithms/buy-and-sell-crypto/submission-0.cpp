class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int l = 0, r = 1;
        while(r < prices.size()){
            if(prices[l] < prices[r]){
                ans = max(ans, (prices[r]-prices[l]));
            }
            else{
                l = r;
            }
            r++;
        }
        return ans;
    }
};
