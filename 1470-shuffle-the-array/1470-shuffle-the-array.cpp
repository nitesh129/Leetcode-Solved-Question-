class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int k=0;
        int j=n;
        int i=0;
        vector<int>ans(n+n);
        while(i<n && j<n+n){
            ans[k]=nums[i];
            ans[k+1] = nums[j];
            i++;
            j++;
            k+=2;
        }
        return ans;
    }
};