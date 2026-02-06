class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l=0;
        int maxkeep =1;
        for(int r=0;r<n;r++){
            while((long long)nums[r] > (long long) k*nums[l]){
                l++;
            }
            maxkeep = max(maxkeep , (r-l+1));
        }
      return n- maxkeep;
    }
};