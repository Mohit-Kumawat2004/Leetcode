class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<array<int, 2>> mp;
        priority_queue<int> pq;
        for (int i = -1; const int& num : nums) mp.push_back({num, ++i});
        sort(begin(mp), end(mp)), pq.push(mp[0][1]);
        for (int i = 1; i < n; pq.push(mp[i++][1])) if (mp[i][0] > mp[i - 1][0] + limit) for (int j = i; !pq.empty(); pq.pop()) nums[pq.top()] = mp[--j][0];
        for (int j = n; !pq.empty(); pq.pop()) nums[pq.top()] = mp[--j][0];
        return nums;
    }
};