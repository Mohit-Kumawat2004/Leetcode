class Solution {
public:
    bool check(vector<int>& nums) {
        const int n=nums.size();
        int cntD=0;
        for(int i=1; i<n && cntD<=1; i++){
            if (nums[i]<nums[i-1]) cntD++;
        }
        return (nums[0]>=nums.back() && cntD==1) || cntD==0;
        
    }
};