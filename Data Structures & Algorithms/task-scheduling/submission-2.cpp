class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char task: tasks){
            mp[task]++;
        }
        int maxi = 0;
        for(auto i:mp){
            maxi = max(maxi, i.second);
        }
        int cnt = 0;
        for(auto i:mp){
            if(i.second==maxi) cnt++;
        }
        int ans = (n+1) * (maxi-1) + cnt;
        int res = max((int)tasks.size(), ans);
        return res;
    }
};
