class Solution {
public:
    typedef pair<int,int>p;
    vector<vector<int>>directions{{-1,0},{0,-1},{1,0},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<p>que;
        int freshcounts=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
                if(grid[i][j]==1){
                    freshcounts++;
                }
            }
        }
        int minutes=0;
        while(!que.empty()){
            int N = que.size();
            while(N--){
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for(auto&dirr : directions){
                     int x_ = x+dirr[0];
                     int y_ = y+dirr[1];
                     if(x_>=0 && x_<m && y_>=0 && y_<n && grid[x_][y_]==1){
                          grid[x_][y_]=2;
                          freshcounts--;
                          que.push({x_,y_});
                     }
                }
            }
            if(!que.empty()) minutes++;
        }
        return freshcounts==0 ? minutes : -1;
    }
};