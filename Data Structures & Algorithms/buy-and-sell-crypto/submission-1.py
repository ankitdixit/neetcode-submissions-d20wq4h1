class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP = 0
        min_price = prices[0]
        for cur_val in prices:
            maxP = max(maxP, cur_val - min_price)
            min_price = min(min_price, cur_val)
        return maxP

        