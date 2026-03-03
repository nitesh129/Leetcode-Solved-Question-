class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        
        // remainder 0 seen at index -1
        mpp[0] = -1;  
    
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            int r = sum % k;
            
            if(mpp.find(r) != mpp.end()) {
                if(i - mpp[r] >= 2) {
                    return true;
                }
            } else {
                // store first occurrence only
                mpp[r] = i;
         }
     }
    
    return false;
    }
};