class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int num:nums){
            mpp[num]++;
        }
        vector<int>ans;
        for(int i=1;i<=nums.size();i++){
            if(mpp[i]==0){
               ans.push_back(i);
            }
        }
        return ans;
    }
};