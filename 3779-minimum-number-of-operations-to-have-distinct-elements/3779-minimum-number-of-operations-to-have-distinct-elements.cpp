class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int num : nums){
            mpp[num]++;
        }
        int dup_count =0;
        for(auto&p : mpp){
            if(p.second > 1){
                dup_count++;
            }
        }
        int i=0;
        int operations=0;
        while(dup_count > 0 && i < n){
            for(int k=0; k<3 && i<n; k++,i++){
                 int value = nums[i];
                 mpp[value]--;
                 if(mpp[value]==1) dup_count--;
            }
            operations++;
        }
      return operations;
    }
};