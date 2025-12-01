class Solution {
public:
    typedef long long ll;
    void dfs(int u , unordered_set<int>&visited , unordered_map<int,vector<int>>&adj){
        visited.insert(u);
        for(int &v : adj[u]){
             if(visited.find(v)==visited.end()){
                    dfs(v,visited,adj);
                }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue; // avoid same bomb
                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll r1 = bombs[i][2];

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];
                ll r2 = bombs[j][2];

                ll distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                if((r1*r1)>=distance) adj[i].push_back(j);
            }
        }
            int result =0;
            unordered_set<int>visited;
            for(int i=0;i<n;i++){
                if(visited.find(i)==visited.end()){
                    dfs(i,visited,adj);
                }
                result = max(result,(int)visited.size());
                visited.clear();
            }
        return result;
    }
};