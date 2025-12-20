class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        unordered_map<int , vector<int>>adj;
        vector<int>indegree(n,0);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>que;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                que.push(i);
            }
        }
        vector<int>result;
        while(n>2){// atmost result vector size is only 2 so we traverse in graph until we have 2 nodes left that are most centered one from leaf nodes
            int size = que.size();
            n-=size;
            while(size--){
                int curr = que.front();
                que.pop();
                for(int &v : adj[curr]){
                    indegree[v]--;
                    if(indegree[v]==1){
                        que.push(v);
                    }
                }
            }
        } 
        while(!que.empty()){
            result.push_back(que.front());
            que.pop();
        }
        return result;
    } 
};