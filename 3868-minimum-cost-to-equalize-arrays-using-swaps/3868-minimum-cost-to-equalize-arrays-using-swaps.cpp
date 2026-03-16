class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {

        auto torqavemin = make_pair(nums1, nums2);

        unordered_map<int,int> total;

        for(int x: nums1) total[x]++;
        for(int x: nums2) total[x]++;

        // check feasibility
        for(auto &p : total){
            if(p.second % 2) return -1;
        }

        unordered_map<int,int> count1;
        for(int x: nums1) count1[x]++;

        vector<int> extra;

        for(auto &p : total){
            int val = p.first;
            int target = p.second / 2;

            if(count1[val] > target){
                for(int i = 0; i < count1[val] - target; i++)
                    extra.push_back(val);
            }
            else if(count1[val] < target){
                for(int i = 0; i < target - count1[val]; i++)
                    extra.push_back(val);
            }
        }

        return extra.size() / 2;
    }
};