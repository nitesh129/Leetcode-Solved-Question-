class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n+n);
        int i=0;
        while(i<2*n){
            ans[i]=nums[i%n];
             i++;
        }
        return ans;
    }
};