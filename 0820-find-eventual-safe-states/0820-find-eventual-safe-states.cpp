class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int , vector<int>>adj;
        int V = graph.size();
         vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
           for(int &v:graph[i]){
                adj[v].push_back(i);
                indegree[i]++;
           }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>safe;
        while(!q.empty()){
            int u = q.front();
            safe.push_back(u);
            q.pop();
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        sort(begin(safe),end(safe));
        return safe;
    }
};