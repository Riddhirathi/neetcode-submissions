class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        for(char task: tasks){
            cnt[task-'A']++;
        }
        priority_queue<int> maxh;
        for(int i: cnt){
            if(i>0) maxh.push(i);
        }
        queue<pair<int,int>> q;
        int time = 0;
        while(!q.empty() || !maxh.empty()){
            time++;
            if(maxh.empty()){
                time = q.front().second;              
            }
            else{
                int ct = maxh.top() - 1;
                maxh.pop();
                if(ct>0){
                    q.push({ct, time+n});
                }
            }

            if(!q.empty() && q.front().second == time){
                maxh.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
