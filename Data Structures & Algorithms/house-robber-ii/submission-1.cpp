class Solution {
public:
    int rob(vector<int>& nums, int s, int e) {
        int n = e-s+1;
        vector<int> dp(n);
        if(n==1) return nums[s];
        if(n==2) return max(nums[s], nums[s+1]);
        dp[0] = nums[s];
        dp[1] = max(nums[s], nums[s+1]);
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], nums[s+i]+dp[i-2]);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        return max(rob(nums, 0, n-2), rob(nums, 1, n-1));
    }
};