class Solution {
public:
    static bool compare(string a , string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string>arr;
        for(int num : nums){
            arr.push_back(to_string(num));
        } 
        sort(begin(arr),end(arr),compare);
        if(arr[0] == "0") return "0";
        string result = "";
        for(string ch : arr){
            result+=ch;
        }
      return result;

    }
};