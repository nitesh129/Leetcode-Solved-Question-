class Solution {
public:
    vector<vector<int>>directions{{-1,0},{0,-1},{1,0},{0,1}};
    typedef pair<int , pair<int ,int>>p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
        result[0][0]=0;
        while(!pq.empty()){
            int diff = pq.top().first;
            auto cord = pq.top().second;
            pq.pop();
            int x = cord.first;
            int y = cord.second;
            for(auto & dirr : directions){
                int x_ = x+dirr[0];
                int y_ = y+dirr[1];
                if(x_>=0 && y_>=0 && x_<m && y_<n ){
                     int absdiff = abs(heights[x][y] - heights[x_][y_]);
                     int maxdiff = max(absdiff,diff); // a route effort is maximum absolute diff of it
                     if(result[x_][y_] > maxdiff){
                         result[x_][y_] = maxdiff;
                         pq.push({maxdiff,{x_,y_}});
                     }
                }
            }
        }
        return result[m-1][n-1];
    }
};