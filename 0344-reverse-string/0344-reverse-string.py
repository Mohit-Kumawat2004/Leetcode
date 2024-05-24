class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Applying Two Pointer Approach
        """
        for i in range(len(s) // 2):     #iterate half of string to get mid point
            s[i], s[-i - 1] = s[-i - 1], s[i]