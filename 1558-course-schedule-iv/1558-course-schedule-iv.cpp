class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        // Map from the node as key to the set of prerequisite nodes.
        unordered_map<int, unordered_set<int>> nodePrerequisites;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adj : adjList[node]) {
                // Add node and prerequisite of node to the prerequisites of adj
                nodePrerequisites[adj].insert(node);
                for (auto prereq : nodePrerequisites[node]) {
                    nodePrerequisites[adj].insert(prereq);
                }

                indegree[adj]--;
                if (!indegree[adj]) {
                    q.push(adj);
                }
            }
        }

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(nodePrerequisites[q[1]].contains(q[0]));
        }

        return answer;
    }
};