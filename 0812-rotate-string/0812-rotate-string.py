class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        str=""
        for i in s:
            str+=s[1:]
            str+=i
            if(str == goal):
                return True
            s=str
            str=""
        return False