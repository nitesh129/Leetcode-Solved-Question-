class Solution {
public:
    typedef pair<int ,int>p;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==0 || n==1) return 0;
        queue<p>que;
        set<p>visited;
        for(int i=0;i<n;i++){
            int maskvalue = (1<<i);
            que.push({i,maskvalue});
            visited.insert({i,maskvalue});
        }
        int allvisited = pow(2,n)-1; // -> (2,n) = (1<<n);
        int path =0;
        while(!que.empty()){
            int size = que.size();
            path++;
            while(size--){
                p curr = que.front();
                que.pop();
                int currnode = curr.first;
                int currmask = curr.second;
                for(auto adj : graph[currnode]){
                     int nextnode = adj;
                     int nextmask = currmask | (1<<nextnode);
                     if(nextmask==allvisited) return path;
                     if(visited.find({nextnode,nextmask})==visited.end()){
                         que.push({nextnode,nextmask});
                         visited.insert({nextnode,nextmask});
                     }
                }
            }
        }
        return -1;
    }
};