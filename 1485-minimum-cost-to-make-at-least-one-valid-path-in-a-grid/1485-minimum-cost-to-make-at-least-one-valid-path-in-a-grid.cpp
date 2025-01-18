class Solution {
public:
    vector<int> xd = {0, 0, 1, -1};
    vector<int> yd = {1, -1, 0, 0};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<tuple<int, int, int>> s;
        s.insert({0, 0, 0});

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        while (!s.empty()) {
            auto [cost, x, y] = *(s.begin());
            s.erase(s.begin());
            if (x == n - 1 && y == m - 1) {
                return cost;
            }
            int p = grid[x][y];
            for (int i = 1; i <= 4; i++) {
                if (x + xd[i - 1] >= 0 && x + xd[i - 1] < n &&
                    y + yd[i - 1] >= 0 && y + yd[i - 1] < m) {
                    if (!(p == i) + dis[x][y] <
                        dis[x + xd[i - 1]][y + yd[i - 1]]) {
                        dis[x + xd[i - 1]][y + yd[i - 1]] =
                            !(p == i) + dis[x][y];
                        s.insert({dis[x + xd[i - 1]][y + yd[i - 1]],
                                  x + xd[i - 1], y + yd[i - 1]});
                    }
                }
            }
        }
        return 0;
    }
};