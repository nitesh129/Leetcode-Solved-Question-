class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x , int y){
        parent[y] = x;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
         parent.resize(n);
         vector<int>cost(n);
         for(int i=0;i<n;i++){
            parent[i]=i;
            cost[i]=-1;
         }
         for(auto &edge : edges){
             int u = edge[0];
             int v = edge[1];
             int wt = edge[2];
             int parent_u = find(u);
             int parent_v = find(v);
             if(parent_u != parent_v){
                Union(parent_u , parent_v);
                cost[parent_u] &= cost[parent_v];
             }
             cost[parent_u] &=wt;
         } 
         vector<int> result;
         for (auto &q : query) {
            int src = q[0];
            int des = q[1];

            int parent_src = find(src);
            int parent_des = find(des);

            if (src == des)
                result.push_back(0);
            else if (parent_src != parent_des)
                result.push_back(-1);
            else
                result.push_back(cost[parent_src]);
        }
        return result;
    }

};