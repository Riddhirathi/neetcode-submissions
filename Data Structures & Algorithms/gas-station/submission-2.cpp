class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot = 0, cur = 0;
        int start = 0;
        for(int i=0; i<gas.size(); i++){
            int bal = gas[i]-cost[i];
            cur += bal; 
            tot += bal;
            if(cur<0){
                cur = 0;
                start = i+1;
            }
        }
        return (tot<0)? -1:start;
    }
};
