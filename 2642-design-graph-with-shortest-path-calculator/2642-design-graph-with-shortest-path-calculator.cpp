class Graph {
public:
    typedef pair<int,int>p;
    int N;
    unordered_map<int,vector<pair<int,int>>>adj;
    priority_queue<p,vector<p>,greater<p>>pq;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        for(auto&vec : edges){
            
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            adj[u].push_back({v,wt});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
        
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>result(N,INT_MAX);
        result[node1] =0;
        pq.push({0,node1});
        while(!pq.empty()){
            p curr = pq.top();
            pq.pop();
            int currnode = curr.second;
            int currweight = curr.first;
            
            for(auto&vec : adj[currnode]){
                 int nextnode = vec.first;
                 int nextweight = vec.second;
                 if(currweight + nextweight < result[nextnode]){
                     result[nextnode] = currweight+nextweight;
                     pq.push({currweight+nextweight , nextnode});
                 }
            }
        }
       return result[node2] == INT_MAX ? -1  : result[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */