class Solution {
public:
   int N;
    class Unionfind{
        public:
            vector<int>parent;
            vector<int>rank;
            Unionfind(int n){
                parent.resize(n);
                rank.resize(n,0);
                for(int i=0;i<n;i++){
                    parent[i]=i;
                }
            };
            int find(int x){
                if(x==parent[x]){
                    return x;
                }
                return parent[x] = find(parent[x]);
            }
            void Union(int x, int y){
                int x_parent= find(x);
                int y_parent = find(y);
                if(x_parent == y_parent) return ;
                if(rank[x_parent] > rank[y_parent]){
                    parent[y_parent] = x_parent;
                }
                else if(rank[y_parent] > rank[x_parent]){
                    parent[x_parent] = y_parent;
                }
                else{
                    parent[y_parent] = x_parent;
                    rank[x_parent]++;
            }
        }
    };
    int kruskalfind(vector<vector<int>>& edges, int skip , int add){
        int sum=0;
        Unionfind uf(N);
         if(add!=-1){
           uf.Union(edges[add][0],edges[add][1]);
            sum+=edges[add][2];
         }
         for(int i=0;i<edges.size();i++){
              if(i==skip) continue;
                int u = edges[i][0]; 
                int v = edges[i][1]; 
                int wt = edges[i][2]; 

                if(uf.find(u)!=uf.find(v)){
                    uf.Union(u,v);
                    sum+=wt;
                }
           } 
           for(int i=0;i<N;i++){
             if(uf.find(i)!=uf.find(0)){
                 return INT_MAX;
             }
           }
           return sum;
        
    }
   
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N=n;
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        auto lambda = [&](vector<int>&vec1 , vector<int>&vec2){
            return vec1[2] < vec2[2];
        };
        sort(begin(edges),end(edges),lambda);

         // step -> 3 making MST using kruskal algo 
         vector<int>critical;
         vector<int>pseudocritical;

         int mst_weight = kruskalfind(edges,-1,-1);
         for(int i=0;i<edges.size();i++){
             if(kruskalfind(edges,i,-1) > mst_weight){
                 critical.push_back(edges[i][3]);
             }
             else if(kruskalfind(edges,-1,i) == mst_weight){
                pseudocritical.push_back(edges[i][3]);
             }
         } 
         return {critical,pseudocritical};

       }
};