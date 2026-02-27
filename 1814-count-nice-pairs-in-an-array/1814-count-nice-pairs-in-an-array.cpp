class Solution {
public:
    int reve(int n){
    string num = to_string(n);
    reverse(num.begin(), num.end());
    return stoi(num);
}
    int countNicePairs(vector<int>& nums) {
     unordered_map<int,int> mpp;
    int ans = 0;
    int mod = 1e9 + 7;

    for(int i = 0; i < nums.size(); i++){
        int rev = reve(nums[i]);
        int key = nums[i] - rev;

        if(mpp.find(key) != mpp.end()){
            ans = (ans + mpp[key]) % mod;
        }

        mpp[key]++;
    }

     return ans;
    }
};