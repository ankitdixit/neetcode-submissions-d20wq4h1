from collections import Counter
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        counts = dict(counter)
        

        heap = []
        for key, count in counts.items():
            heapq.heappush(heap, (count, key))
            if len(heap) > k:
                heapq.heappop(heap)
        res = []
        for i in range(len(heap)):
            res.append(heapq.heappop(heap)[1])
        return res

        
        


