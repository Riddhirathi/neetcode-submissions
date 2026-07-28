class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r = nums.size()-1;
        int mid = (l-r)/2 + r;
        while(l<=r){
            mid = (l-r)/2 + r;
            if(nums[mid]<target) l = mid+1;
            else if(nums[mid]>target) r = mid-1;
            else return mid;
        }
        return -1;
    }
};
