class Solution {
public:
    vector<vector<int>>directions{{-1,0},{0,-1},{0,1},{1,0}};
    void solve(int sr,int sc , vector<vector<int>>& image , int &color,int m,int n, vector<vector<int>>&ans,int originalcolor){
         for(auto & dirr : directions){
             int new_i = sr+dirr[0];
             int new_j = sc+dirr[1];
             if(new_i<0 || new_i>=m || new_j <0 || new_j >=n) continue;
             if(image[new_i][new_j] ==originalcolor && ans[new_i][new_j] != color){
                 ans[new_i][new_j] = color;
                 solve(new_i,new_j,image,color,m,n,ans,originalcolor);
             }
            
         } 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int m = image.size();
        int n = image[0].size();
        int originalcolor = image[sr][sc];
        if(originalcolor==color) return ans;
        ans[sr][sc]=color;
        solve(sr,sc,image,color,m,n,ans,originalcolor);
        return ans;
    }
};