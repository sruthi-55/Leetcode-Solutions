
    
class Solution:
    def buildArray(self, nums):
        n = len(nums)
        for i in range(0, len(nums)):
            nums[i]=nums[i]+(n*(nums[nums[i]]%n))

        for i in range(0, len(nums)):
            nums[i] = int(nums[i]/n)

        return nums