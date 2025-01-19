class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(); 
        if (n == 0) return 0; 
        int m = heightMap[0].size();
        int total = 0; 
        vector<vector<bool>> visited(n, vector<bool>(m, false)); 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; 

        // Add boundary cells to the priority queue row by row
        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < m; ++j) { 
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) { 
                    pq.push({heightMap[i][j], {i, j}}); 
                    visited[i][j] = true; 
                }
            }
        }

        int dx[4] = {0, 0, 1, -1}; 
        int dy[4] = {1, -1, 0, 0}; 

        while (!pq.empty()) {
            int h = pq.top().first; // Current water level
            int x = pq.top().second.first; 
            int y = pq.top().second.second; 
            pq.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d]; 
                int ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true; 
                    pq.push({max(h, heightMap[nx][ny]), {nx, ny}}); 
                    // Calculate trapped water at the neighbor
                    total += max(0, h - heightMap[nx][ny]); 
                }
            }
        }

        return total;
    }
};