class Solution {
    public int[] searchRange(int[] nums, int target) {
        
        int arr[] = new int [2];     //result array
        int f=0,l=0;              //half binary search
        
        Arrays.fill(arr,-1);            //initialize all -1
        
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i] == target && f==0)          //first fill
            {
                arr[0]=i;
                f++;
            }
            if(nums[i] == target && f!=0)     //second fill
            {
                arr[1]=i;
                l++;
            }
        }
        
        if(l==0 && f!=0)
        {
            arr[1] = nums.length-1;
        }
        
        return arr;
    }
}