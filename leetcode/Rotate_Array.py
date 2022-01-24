class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        steps = k % len(nums) # the result is repeated based on the length
        # whole list = latter list thats cut off + former list thats pushed up
        nums[:] =  nums[-k:] + nums[:-k]
            