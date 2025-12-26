class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // using the floydd warshall algo 
        vector<vector<int>>dist(n,vector<int>(n,1e7));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto &e : edges){
            int u = e[0] , v = e[1] , wt = e[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        // apply floyd warsshall 
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }
      int anss =-1 , min_reach = INT_MAX;
      for(int i=0;i<n;i++){
           int count =0;
          for(int j=0;j<n;j++){
              if(i!=j && dist[i][j] <= distanceThreshold){
                  count++;
              }
          }
          if(count<= min_reach){
             min_reach = count;
             anss=i;
          }
      }
      return anss;

    }
};