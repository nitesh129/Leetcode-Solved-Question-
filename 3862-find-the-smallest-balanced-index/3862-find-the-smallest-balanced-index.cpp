class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long double>sum(n);
        vector<long double>pro(n);
        sum[0] =0;
        pro[n-1] = 1;
        for(int i=1;i<n;i++){
            sum[i] = nums[i-1] + sum[i-1];
        }
        for(int i=n-2;i>=0;i--){
            pro[i] = (long double)nums[i+1]*pro[i+1];
        }
        
        for(int i=0;i<n;i++){
            if(sum[i] == pro[i]){
                return i;
            }
        }
        return -1;
    }
};