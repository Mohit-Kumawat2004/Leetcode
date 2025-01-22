class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        ways = 0
        total = sum(nums)
        left_sum = 0
        for i in range(len(nums)-1):
            left_sum += nums[i]
            if left_sum >= (total - left_sum):
                ways += 1
        return ways