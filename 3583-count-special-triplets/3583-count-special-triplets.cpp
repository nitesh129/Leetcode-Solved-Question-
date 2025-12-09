class Solution {
public:
    int M = 1e9 +7;
    int specialTriplets(vector<int>& nums) {
        long long  count  =0;
        unordered_map<int,long long>left,right;
        for(int x : nums){
            right[x]++;
        }
        for(int j=0;j<(int)nums.size();j++){
            int mid = nums[j];
            right[mid]--;
            long long  need = 2LL * mid;
            if(left.count(need) && right.count(need)){
                count+= right[need]*left[need];
                if (count >= 8LL * M) count %= M;
            }
           left[mid]++;
        }
        count%=M;
        if (count < 0) count += M;
        return (int)count%M;
    }
};