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
        vector<bool>safe(V,false);
        while(!q.empty()){
            int u = q.front();
            safe[u]=true;
            q.pop();
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        // sort(begin(safe),end(safe)); // 
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};