class Solution:
    def minChanges(self, s: str) -> int:
        ptr = 1
        cur_len = 1
        num_changes = 0

        while ptr < len(s):
            if s[ptr] != s[ptr-1]:
                if cur_len % 2 != 0:
                    num_changes += 1
                    cur_len += 1
                else:
                    cur_len = 1
            else:
                cur_len += 1
            
            ptr += 1

        
        return num_changes