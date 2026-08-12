class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = set()
        n = len(nums)
        for i in range(n-2):
            if nums[i] > 0:
                break
            rem = -nums[i]
            start = i+1
            end = n - 1
            print (f"i : {i}, start :{start}, end :{end}")
            while start < end:
                sum = nums[start] + nums[end]
                if rem == sum:
                    res.add((nums[i], nums[start], nums[end]))
                    start += 1
                    end -= 1
                elif sum < rem:
                    start += 1
                else :
                    end -= 1
        return list(res)
