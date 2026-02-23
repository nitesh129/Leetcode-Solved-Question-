class Solution {
public:

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int,long long>mpp;
        long long result = INT_MIN;
        for(int i=0;i<n;i++){
            auto it = mpp.upper_bound(nums[i]-i);
            long long sum = nums[i];
            if(it!=mpp.begin()){
                it--;
                sum+=it->second;
            }
            mpp[nums[i]-i] = max(mpp[nums[i]-i],sum);
            it = mpp.upper_bound(nums[i]-i);
            while(it!=mpp.end() && it->second <= sum){
                mpp.erase(it++);
            }
            result = max(result,sum);
        }
        return result;
    }
};