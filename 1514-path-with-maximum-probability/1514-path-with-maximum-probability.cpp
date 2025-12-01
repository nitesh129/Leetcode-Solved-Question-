class Solution {
public:
    typedef pair<double,int>p;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        if(start_node==end_node) return 1.0;
        unordered_map<int,vector<pair<int ,double>>>adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<double>result(n,0.0);
        priority_queue<p>que;
        que.push({1.0,start_node});
        result[start_node] = 1.0;
        while(!que.empty()){
            auto p = que.top();
            que.pop();
            double succ_pro = p.first;
            int u = p.second;
            if(result[u] > succ_pro) continue;
            if(u==end_node) return succ_pro;
            for(auto &vec:adj[u]){
                int src = vec.first;
                double prob = vec.second;
                double newprob = prob*succ_pro;
                if(newprob > result[src]){
                     result[src] = newprob;
                     que.push({newprob,src});
                }
            }
        }
      return result[end_node];
     
    }
};