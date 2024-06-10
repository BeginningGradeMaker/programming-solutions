class Solution:
    def maxTotalReward(self, nums: List[int]) -> int:
        f = 1
        for x in sorted(set(nums)):
            bitmask = (1 << x) - 1
            f |= (f & bitmask) << x
        
        return f.bit_length() - 1
        
