class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>nums2 = nums;
        sort(begin(nums2),end(nums2));
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end()); // remove unique elements 
        int m = nums.size();
        int n = nums2.size();
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(nums[i-1] == nums2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        return t[m][n];

    }
};