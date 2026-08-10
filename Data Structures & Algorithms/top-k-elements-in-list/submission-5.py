class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for num in nums:
            count[num] = 1 + count.get(num, 0)
        
        l :list[tuple[int, int]]= []
        for num, cnt in count.items():
            l.append([cnt, num])
        l.sort()
        res = []
        while len(res) < k:
            res.append(l.pop()[1])
        return res
        