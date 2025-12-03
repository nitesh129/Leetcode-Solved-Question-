class Solution {
public:
      int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>indegree(n+1,0);
        unordered_map<int,vector<int>>adj(n+1);
        for(auto &vec : relations){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        // now push all the nodes in queue that have indegree zero along with there time;
        vector<int>dist(n+1,0);
        queue<int>que;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                que.push(i);
                dist[i] = time[i-1]; // stores the least time required by ith node;
            }
        }
        int ans =0;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            ans = max(ans,dist[u]);
            for(int &v : adj[u]){
                dist[v] = max(dist[v] , dist[u] + time[v-1]);
                if(--indegree[v]==0){
                    que.push(v);
                }
            }
        }
        return ans;
        
    }

};