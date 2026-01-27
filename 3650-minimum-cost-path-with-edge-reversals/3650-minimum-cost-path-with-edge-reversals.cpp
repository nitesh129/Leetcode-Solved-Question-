class Solution {
public:
    typedef pair<int,int>p;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto & vec : edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});  
        }
        vector<int>ans(n,1e9);
        ans[0]=0;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int u = p.second;
            for(auto &vec : adj[u]){
                int wt = vec.second;
                int node = vec.first;
                if(d+wt< ans[node]){
                    ans[node] = d+wt;
                    pq.push({d+wt , node});
                }
            }
        }
        return ans[n-1] == 1e9 ? -1 : ans[n-1];
    }
};