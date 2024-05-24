class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d=defaultdict(lambda:0) 
        for i in range(len(nums1)):
            d[nums1[i]]=i 
        st,ans=[],[0]*len(nums1) 
        j=len(nums2)-1 
        while j>=0:
            if nums2[j] in d:
                if st==[]:
                    ans[d[nums2[j]]]=-1 
                elif st!=[] and st[-1]>nums2[j]:
                    ans[d[nums2[j]]]=st[-1] 
                elif st!=[] and st[-1]<=nums2[j]:
                    while st!=[] and st[-1]<=nums2[j]:
                        st.pop() 
                    if st==[]:
                        ans[d[nums2[j]]]=-1 
                    else:
                        ans[d[nums2[j]]]=st[-1]
            st.append(nums2[j]) 
            j-=1 
        return ans