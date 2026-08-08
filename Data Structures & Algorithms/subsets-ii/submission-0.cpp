class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(vector<int>& nums, int start){
        ans.push_back(temp);
        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i-1]==nums[i]){
                continue;
            }
            temp.push_back(nums[i]);
            dfs(nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};
