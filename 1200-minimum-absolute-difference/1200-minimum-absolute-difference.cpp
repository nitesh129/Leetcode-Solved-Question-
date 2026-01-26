class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        vector<vector<int>>result;
        int n = nums.size();
        sort(begin(nums),end(nums));
        int min_diff = INT_MAX;
        for(int i=0;i<n-1;i++){
            min_diff = min(min_diff , abs(nums[i+1] - nums[i]));
        }
        for(int i=0;i<n-1;i++){
            int diff = abs(nums[i]-nums[i+1]);
            if(diff == min_diff){
                 vector<int>temp;
                 temp.push_back(nums[i]);
                 temp.push_back(nums[i+1]);
                 result.push_back(temp);
            }
        }
        return result;

    }
};