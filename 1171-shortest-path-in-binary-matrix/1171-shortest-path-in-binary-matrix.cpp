class Solution {
public:
    vector<vector<int>>directions{{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]!=0) return -1;
        // vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        int level =0;
        grid[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int N = q.size();
            while(N--)
           {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == m-1 && y==n-1) return level+1;
                for(auto & dirr: directions){
                    int x_ = x+dirr[0];
                    int y_ = y+dirr[1];
                    if(x_>=0 && y_>=0 && x_<m && y_<n && grid[x_][y_]==0){
                        q.push({x_,y_});
                        grid[x_][y_]=1;
                    }
                }
            }
            level++;
        }
      return -1;
    }
};