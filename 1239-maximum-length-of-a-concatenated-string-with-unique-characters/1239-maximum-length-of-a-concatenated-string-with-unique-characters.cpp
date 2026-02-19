class Solution {
public:
    bool isvalid(string &s){
        int freq[26] = {0};
        for(char ch : s){
            if(freq[ch-'a']>0) return false;
            freq[ch-'a']++;
        }
        return true;
    }
    int solve(int indx , string curr , vector<string>&arr){
        if(indx>=arr.size()){
           return curr.length();
        }
        int take =0,not_take =0;
        string compressed = curr + arr[indx];
        if(isvalid(compressed)){
            take = solve(indx+1,compressed,arr);
        }
        not_take = solve(indx+1,curr,arr);
        return max(take,not_take);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        return solve(0,"",arr);
    }
};