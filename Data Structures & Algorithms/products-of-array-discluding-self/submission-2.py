class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product = 1
        zero_cnt = 0
        for i in nums:
            if i != 0:
                product = product*i
            else:
                zero_cnt += 1
        res = [0]*len(nums)
        for i, c in enumerate(nums):
            if zero_cnt > 1:
                res[i] = 0
            elif zero_cnt: res[i]=0 if c else product
            else: res[i]=product//c
        return res