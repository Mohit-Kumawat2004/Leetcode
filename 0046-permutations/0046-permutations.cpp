class Solution {
public:
    void rec(int idx,vector<int>&nums,vector<vector<int>>&ans){
        //if our index reached nums.size() then we will and the nums in ans and return
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        //we are traversing from idx to nums.size() and swapping the nums[i] and nums[idx]
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            rec(idx+1,nums,ans);
            //backtracking 
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //we have created the ans vector for storing all the permutation in it
        vector<vector<int>>ans;
        //we are calling recursive function for the 0th index
        rec(0,nums,ans);
        return ans;
    }
};
