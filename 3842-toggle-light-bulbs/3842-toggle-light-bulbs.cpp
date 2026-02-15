class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int num : bulbs) mpp[num]++;
        for(int i=0;i<bulbs.size();i++){
           if(mpp[bulbs[i]] %2 ==0) continue;
           ans.push_back(bulbs[i]);
        }
        unordered_set<int>st (begin(ans),end(ans));
        vector<int>result;
        for(auto it : st){
            result.push_back(it);
        }
        sort(begin(result),end(result));
        return result;
    }
};