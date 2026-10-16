class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numset = set(nums)
        long = 0
        for i in numset:
            if (i-1) not in numset:
                length = 1
                while (i+length) in numset:
                    length += 1
                long = max(length, long)
        return long