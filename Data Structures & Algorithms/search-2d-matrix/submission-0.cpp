class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m*n-1;
        int mid = (r-l)/2 + l;
        while(l<=r){
            mid = (r-l)/2 + l;
            if(matrix[mid/n][mid%n]<target){
                l = mid+1;
            }
            else if(matrix[mid/n][mid%n]>target){
                r = mid-1;
            }
            else if(matrix[mid/n][mid%n]==target){
                return true;
            }
            else return false;
        }
        return false;
    }
};
