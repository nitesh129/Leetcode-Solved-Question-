class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        long long result = LLONG_MIN;
        for(int start =0;start<k;start++){
            long long currsum=0;
             int i = start;
             while(i<n && i+k-1 < n){
                int j = i+k-1;
                long long subsum = pre[j] - ((i>0) ? pre[i-1]:0);
                currsum = max(subsum , currsum+subsum);
                result = max(result,currsum);
                i+=k;
             }
        }
        return result;
    }
};