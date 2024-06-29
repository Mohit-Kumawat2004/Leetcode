class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);
        vector<unordered_map<int,bool>> done(n);
        vector<int> indegree(n,0);
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(auto i:adj[t])
            {
                for(auto j:ans[t]) {
                    if(done[i][j]==0){
                        ans[i].push_back(j);
                        done[i][j]=1;
                    }
                }
                if(done[i][t]==0){
                        ans[i].push_back(t);
                        done[i][t]=1;
                    }
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        for(auto &i:ans)
        {
            sort(i.begin(),i.end());
        }
        return ans;
    }
};