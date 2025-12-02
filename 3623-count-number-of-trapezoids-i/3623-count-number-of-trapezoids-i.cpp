class Solution {
public:
    int M = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mpp;
        for(auto &point : points){
            int y = point[1];
            mpp[y]++;
        }
       long long result = 0;
       long long prevhorizontallines = 0;
       for(auto &it: mpp){
          int count = it.second;
          long long horizontallines = (long long)count * (count-1)/2;
           result+= horizontallines *  prevhorizontallines;
           prevhorizontallines+=horizontallines;
       }
       return result % M;
    }
};