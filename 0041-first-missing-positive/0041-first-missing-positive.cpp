class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int num : nums){
            mpp[num]++;
        }
        for(int i=1;i<=n;i++){
            if(mpp[i]==0) {
                return i;
            }
        }
       return n+1;
    }
};