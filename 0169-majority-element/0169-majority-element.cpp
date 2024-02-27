class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt == 0)
            {
                //starting a check for a new section
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el)
            {
                //if not 0 then assuming majority element is nums[i]
                cnt++;
            }
            else
            {
                //reduce the number
                cnt--;
            }
        }
        
        int cnt1 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == el) cnt1 ++;
        }
        if(cnt1 > (nums.size()/2))
        {
            return el;
        }
        
        return 1;
    }

};