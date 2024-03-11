class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=1;
        
        for(int i=1;i<n;i++) 
        {
            if(nums[i]!=nums[i-1])
            {
                //stroing val in kth index then increasing index of k
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};


//another approach using two pointers
/*
int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        
        for(int j=1;j<n;j++) 
        {
            if(nums[i]!=nums[j])
            {
                //Take my place and comes to my position 
                nums[i++]=nums[j];
            }
        }
        return i+1;
*/