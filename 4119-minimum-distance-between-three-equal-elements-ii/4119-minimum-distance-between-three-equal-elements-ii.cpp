class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int , vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int n = nums.size();
        if(n<3) return -1;
        // if(mpp.size()==1) return n;
        int ans = INT_MAX;
        for(auto &x : mpp){
            vector<int>temp = x.second;
            if(temp.size()<3) continue;
            for(int l=0;l<temp.size()-2;l++){
                 int i = temp[l];
                 int j = temp[l+1];
                 int k = temp[l+2];
                 ans = min(ans , (abs(i-j) + abs(j-k) + abs(k-i)));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};