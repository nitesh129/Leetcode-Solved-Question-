class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>pos;
        for(int x : nums){
            if(x>=0){
                pos.push_back(x);
            }
        }
        int m = pos.size();
        if(m==0) return nums;
        k=k%m;
        vector<int>Lrotated;
        for(int i=k;i<m;i++){
            Lrotated.push_back(pos[i]);
        }
        for(int i=0;i<k;i++){
            Lrotated.push_back(pos[i]);
        }
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
              nums[i] = Lrotated[idx++];
            }
        }
        return nums;
   }
};