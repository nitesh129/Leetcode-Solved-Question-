class Solution {
public:
    void dfs(int anc , unordered_map<int,vector<int>>&adj, int currnode , vector<vector<int>>&result){
        for(int &ngbr : adj[currnode]){
            if(result[ngbr].empty() || result[ngbr].back() != anc){
                result[ngbr].push_back(anc);
                dfs(anc,adj,ngbr,result);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<vector<int>>result(n);
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            dfs(i,adj,i,result);
        }
        return result;
    }
};
