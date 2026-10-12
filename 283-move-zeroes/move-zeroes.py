class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count=0
        for i in range(len(nums)):
            if nums[i]==0:
                count=count+1
        

        vec=[]
        for i in range(len(nums)):
            if nums[i]!=0:
                vec.append(nums[i])

        
        for i in range(count):
            vec.append(0)


        nums[:]=vec
        return nums