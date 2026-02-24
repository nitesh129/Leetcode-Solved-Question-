class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<int>t(n,1);
        vector<int>prev(n,-1);
        vector<int>ans;
        int maxlen = INT_MIN;
        int lastindx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] ==0){
                    if(t[i] < t[j]+1){
                        t[i] = t[j]+1;
                        prev[i] =j;
                    }
                    if(t[i] > maxlen){
                        maxlen = t[i];
                        lastindx=i;
                    }

                }
            }
        }

        while(lastindx!=-1){
            ans.push_back(nums[lastindx]);
            lastindx = prev[lastindx];
        }
        return ans;
    }
};