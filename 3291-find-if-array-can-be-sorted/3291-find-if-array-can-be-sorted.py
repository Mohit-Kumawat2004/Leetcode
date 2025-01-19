class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        bits={}
        for n in nums:
            ct=0
            m=n
            while n>0:
                if n%2!=0:
                    ct+=1
                n=n//2
            bits[m]=ct
        print(bits)
        
        current_bit=bits[nums[0]]
        last_max=-sys.maxsize
        current_max=-sys.maxsize
        current_min=sys.maxsize
        for i in range(len(nums)):
            if bits[nums[i]]==current_bit:
                current_max=max(current_max, nums[i])
                current_min=min(current_min, nums[i])
            else:
                if current_min<last_max: return False
                current_bit=bits[nums[i]]
                last_max=current_max
                current_max=nums[i]
                current_min=nums[i]
        if current_min<last_max: return False 
        return True
