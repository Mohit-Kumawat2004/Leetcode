function getFinalState(nums: number[], k: number, multiplier: number): number[] {
    for(let i = 0; i < k; ++i) {
        let index = nums.indexOf(Math.min(...nums))
        nums[index] *= multiplier
    }
    return nums
};