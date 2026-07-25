class Solution {
public:
    int fn(vector<int>& nums, int i, int j){
        int mx = nums[i];
        while(i<=j){
            mx = max(mx, nums[i]);
            i++;
        }
        return mx;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0, j=0;
        vector<int> ans;
        while(j<nums.size()){
            int mx;
            if(j-i+1 == k){
                mx = fn(nums, i,j);
                ans.push_back(mx);
                i++;
            }
            j++;
        }
        return ans;
    }
};
