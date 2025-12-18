class Solution {
public:
    typedef pair<int ,int>p;
    void dijkstra( unordered_map<int , vector<p>>&adj , int src , vector<int>&ans){
        priority_queue<p,vector<p>,greater<p>>que;
        ans[src]=0;
        que.push({0,src});
        while(!que.empty()){
            auto p = que.top();
            que.pop();
            int curr_dis = p.first;
            int curr_node = p.second;
            for(auto &vec : adj[curr_node]){
                int des_node = vec.first;
                int des_dis = vec.second;
                if(curr_dis + des_dis < ans[des_node]){
                    ans[des_node] = curr_dis + des_dis;
                    que.push({des_dis + curr_dis , des_node});
                }
            }
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int mx = 1e7;
        unordered_map<int , vector<p>>adj;
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        // now make the double ended dijkstra
        vector<int>source_to_min(n,mx);
        vector<int>des_to_min(n,mx);
        dijkstra(adj,0,source_to_min);
        dijkstra(adj,n-1,des_to_min);
        vector<bool>result;
        int min_dis = source_to_min[n-1];
        for(auto & query : edges){
            int u = query[0];
            int v = query[1];
            int wt = query[2];

            int x = source_to_min[u];
            int y = des_to_min[v];
            int new_x = source_to_min[v];
            int new_y = des_to_min[u];
            if((x+wt+y) == min_dis) result.push_back(true);
            else if(new_x + wt + new_y == min_dis) result.push_back(true);
            else  result.push_back(false);
            
        }
        return result;
    }
};