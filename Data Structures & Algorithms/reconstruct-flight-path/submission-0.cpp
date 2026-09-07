class Solution {
public:
    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    void dfs(string airport){
        while(!graph[airport].empty()){
            string next = graph[airport].top();
            graph[airport].pop();
            dfs(next);
        }
        ans.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto i: tickets){
            string from = i[0];
            string to = i[1];
            graph[from].push(to);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
