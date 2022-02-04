from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        my_dict = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            # if in the map try to see if its complementing the target
            if (my_dict.get(complement) != None):
                return [i, my_dict.get(complement)]
            # else put in the map
            else:
                my_dict[nums[i]] = i

        print("You shouldn't get to this point by requirment")
        return [0]
