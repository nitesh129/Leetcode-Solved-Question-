class Solution {
public:
    typedef pair<int ,int>p;
    vector<vector<int>>directions{{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<p>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                     q.push({i,j});
                     ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for(auto &dirr : directions){
                    int x_ = x+dirr[0];
                    int y_= y+dirr[1]; 
                    if(x_>=0 && x_<m && y_>=0 && y_<n && ans[x_][y_]==-1){
                        q.push({x_,y_});
                        int value = ans[x][y];
                        ans[x_][y_]=value+1;
                    }
                }
            }
        }
        return ans;
    }
};