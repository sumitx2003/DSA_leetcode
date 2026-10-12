class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        count=0
        res=0

        for i in range(len(nums)):
            if nums[i]==1:
                count+=1
                res=max(count,res)
            else:
                count=0
            
        return res        