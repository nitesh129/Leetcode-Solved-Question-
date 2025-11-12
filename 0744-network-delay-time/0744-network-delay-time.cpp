class Solution {
public:
    typedef pair<int ,int>p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int ,vector<pair<int,int>>>adj;
        for(auto&vec:times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v,w});
        }
        vector<int>result(n+1,INT_MAX);
        priority_queue<p,vector<p>,greater<p>>q;
        result[k]=0;
        q.push({0,k});
        while(!q.empty()){
            int d = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto & vec : adj[node]){
                int dist = vec.second;
                int adjnode = vec.first;
                if(d+dist < result[adjnode]){
                    result[adjnode] = d+dist;
                    q.push({d+dist,adjnode});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            ans = max(ans,result[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};