class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size()-1, l=0;
        int mid;
        while(r>=l){
            mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[l]){
                if(target<nums[mid] && target>=nums[l]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                if(target > nums[mid] && target<nums[l]){
                    l =mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};