class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string,int>mpp;
        int i=0,j=0;
        vector<string>ans;
        string curr = "";
        while(j<n){
            curr+=s[j];
            if(j-i+1==10){
                if(mpp[curr] == 1){
                    ans.push_back(curr);
                }
                mpp[curr]++;
                i++;
                curr.erase(0,1); // humesha 0th indx vala char erase karna ha 1 length ka
            }
            j++;
        }
      return ans;
    }
};