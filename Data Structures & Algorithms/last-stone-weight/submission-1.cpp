class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for(int num: stones){
            maxh.push(num);
        }
        while(maxh.size()>1){
            int y = maxh.top();
            maxh.pop();
            int x = maxh.top();
            maxh.pop();
            if(x!=y){
                maxh.push(y-x);
            }
        }
        if(maxh.empty()) return 0;
        else return maxh.top();
    }
};
