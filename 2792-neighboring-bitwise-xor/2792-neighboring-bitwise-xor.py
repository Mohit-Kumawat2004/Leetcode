class Solution:
    def doesValidArrayExist(self, a: List[int]) -> bool:
        return reduce(xor,a)==0
