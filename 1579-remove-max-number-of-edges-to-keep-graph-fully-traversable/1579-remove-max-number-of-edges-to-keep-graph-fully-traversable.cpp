class Solution {
public:
    class DSU{
        public:
            vector<int>parent;
            vector<int>rank;
            int component;
            DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            component = n;
            for(int i=1;i<=n;i++){
                    parent[i] = i;
            }
            }
            int find(int x){
                if(x==parent[x]){
                    return x;
                }
                return parent[x] = find(parent[x]);
            }
            void Union(int x , int y){
                int x_parent = find(x);
                int y_parent = find(y);
                if(x_parent == y_parent) return ;
                if(rank[x_parent]>rank[y_parent]) parent[y_parent] = x_parent;
                else if(rank[y_parent]>rank[x_parent]) parent[x_parent] = y_parent;
                else{
                    parent[y_parent] = x_parent;
                    rank[x_parent]++;
                }
                component--;
            }
            bool issinglecomponent(){
                return component ==1;
            }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);
        auto lambda = [&](vector<int>&vec1 , vector<int>&vec2){
            return vec1[0] > vec2[0];
        };
        sort(begin(edges),end(edges),lambda);
        int edgecount =0;
        for(auto& vec : edges){
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];
            bool edgematch = false;
            if(type == 3){
                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    edgematch = true;
                }
                 if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    edgematch = true;
                }
                if(edgematch) edgecount++;
            }
            else if(type ==2){
                  if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    edgematch = true;
                }
                if(edgematch) edgecount++;
            }
            else {
                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    edgematch = true;
                }
                 if(edgematch) edgecount++;
            }
        }
        if(Alice.issinglecomponent() && Bob.issinglecomponent()) return edges.size() - edgecount;
        return -1;

    }
};