class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        for(auto &p: prerequisites){
            int course = p[0];
            int pre = p[1];
            graph[pre].push_back(course);
            indegree[course]++;
        }
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for(int next: graph[course]){
                indegree[next]--;
                if(indegree[next]==0) q.push(next);
            }
        }
        if(numCourses != ans.size()) return {};
        return ans;
    }
};
