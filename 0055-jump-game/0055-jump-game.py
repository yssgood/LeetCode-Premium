class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxJump = 0
        for index in range(0, len(nums)):
            if(index > maxJump) : return False
            maxJump = max(maxJump, index + nums[index])
            if(maxJump >= len(nums)-1) : return True 
        return True