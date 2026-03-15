class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixgcd(n);
        prefixgcd[0] = nums[0];
        int maxi = nums[0];
        for(int i=1;i<n;i++){
            maxi = max(maxi , nums[i]);
            prefixgcd[i] = gcd(nums[i] , maxi);
        }
        sort(begin(prefixgcd),end(prefixgcd));
        int i=0;
        int j = prefixgcd.size()-1;
        long long sum =0;
        while(i<j){
           sum+=gcd(prefixgcd[i] , prefixgcd[j]);
           i++;
           j--;
        }
        return sum;

    }
};