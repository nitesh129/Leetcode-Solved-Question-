class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans =0;
        int n = nums.size();
        int i=0,j=0;
        long long sum =0;
        while(j<n){
          sum+=nums[j];
          while(sum*(j-i+1) >= k){
              sum-=nums[i];
              i++;
          }
          if(sum*(j-i+1) < k){
              ans+=j-i+1;
          }
          j++;
        }
        return ans;
    }
};