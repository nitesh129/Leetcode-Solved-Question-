class Solution {
public:
    vector<int> toposort( vector<vector<int>>&edges , int &n){
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n+1,0);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        int count =0;
        vector<int>topoorder;
        queue<int>que;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();
            topoorder.push_back(u);
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                    count++;
                }
            }
        }
        if(count == n) return topoorder;
        else return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>toporow = toposort(rowConditions,k);
        vector<int>topocol = toposort(colConditions,k);

        if(toporow.empty() || topocol.empty()) return {}; // detect cycle 

        vector<vector<int>>matrix(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(toporow[i]==topocol[j]){
                   matrix[i][j] = topocol[j];
                }
            }
        }
        return matrix;
    }
};