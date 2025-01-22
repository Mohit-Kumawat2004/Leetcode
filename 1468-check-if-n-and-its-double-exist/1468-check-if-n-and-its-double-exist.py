class Solution(object):
    def checkIfExist(self, arr):
        l=len(arr)
        for i in range(l):
            for j in range(i+1,l):
                if arr[i]==arr[j]*2 or arr[j]==arr[i]*2:
                    return True
        return False  