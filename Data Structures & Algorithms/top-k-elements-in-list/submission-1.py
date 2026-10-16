class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        arr = [[] for i in range(len(nums)+1)]
        count = {}
        for num in nums:
            count[num] = 1+count.get(num, 0)
        for num, cnt in count.items():
            arr[cnt].append(num)
        res = []
        for i in range(len(arr)-1, 0, -1):
            for num in arr[i]:
                res.append(num)
                if len(res)==k:
                    return res