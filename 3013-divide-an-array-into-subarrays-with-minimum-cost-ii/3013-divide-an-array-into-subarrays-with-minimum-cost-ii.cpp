class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll>p;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<p>kmin;
        set<p>rem;
        ll sum =0;
        int i=1;
        while(i-dist < 1){
            kmin.insert({nums[i] , i});
            sum+=nums[i];
            if(kmin.size() > k-1){
                p temp = *kmin.rbegin();
                sum-=temp.first;
                rem.insert(temp);
                kmin.erase(temp);
            }
            i++;
        }
        // it's time to shrink window 
        ll result = LONG_MAX;
        while(i<n){
            kmin.insert({nums[i] , i});
            sum+=nums[i];
            if(kmin.size() > k-1){
                p temp = *kmin.rbegin();
                sum-=temp.first;
                rem.insert(temp);
                kmin.erase(temp);
            }
            result = min(result,sum);
            // shift window;
            p remove = {nums[i-dist] , i-dist};
            if(kmin.count(remove)){
                kmin.erase(remove);
                sum-=remove.first;

                if(!rem.empty()){
                    p temp = *rem.begin();
                    kmin.insert(temp);
                    sum+=temp.first;
                    rem.erase(temp);
                }
            }
            else rem.erase(remove);
            i++;
        }

        return nums[0] + result;
    }
};