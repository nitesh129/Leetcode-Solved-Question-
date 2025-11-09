class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans =INT_MAX;
        if(nums.size()<3) return -1;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]){
                        ans = min(ans, (abs(i-j) + abs(j-k) + abs(k-i)));
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};