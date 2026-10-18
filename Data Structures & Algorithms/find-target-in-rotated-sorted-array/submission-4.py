class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while l<r:
            m = (l+r)//2
            if nums[m]>nums[r]:
                l = m+1
            else:
                r = m
        pivot = l

        l, r = 0, len(nums)-1
        if target>=nums[pivot] and target<=nums[r]:
            l = pivot
        else:
            r = pivot-1

        while l<=r:
            mid = (l+r)//2
            if nums[mid]==target:
                return mid
            elif nums[mid]<target:
                l = mid+1
            else:
                r = mid-1
        return -1
        
        