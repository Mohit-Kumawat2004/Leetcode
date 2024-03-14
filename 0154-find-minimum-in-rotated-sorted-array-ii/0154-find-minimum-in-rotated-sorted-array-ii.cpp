class Solution {
public:
    int findMin(vector<int>& nums) {
        
        //Easiest way using two pointers approach
        int start = 0;
        int end = nums.size()-1;

        while(start < end)
        {
            if(nums[start] <= nums[end])
                end--;
            else if(nums[start] > nums[end])
                start++;
        }
        return nums[start];
    }
};