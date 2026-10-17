class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        l, r = 0, len(height)-1
        leftmax, rightmax = height[l], height[r]
        res = 0
        while l<r:
            if height[l]<=height[r]:
                leftmax = max(leftmax, height[l])
                res += leftmax-height[l]
                l+=1
            else:
                rightmax = max(rightmax, height[r])
                res += rightmax-height[r]
                r-=1
        return res