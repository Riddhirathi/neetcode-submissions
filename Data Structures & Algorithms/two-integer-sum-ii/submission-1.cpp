class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i=0, j=n-1;
        while(i<j){
            int curSum = numbers[i]+numbers[j];
            if(curSum<target){
                i++;
            }
            else if(curSum>target){
                j--;
            }
            else{
                return {i+1, j+1};
            }
        }
        return {};
    }
};
