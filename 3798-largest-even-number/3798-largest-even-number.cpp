class Solution {
public:
    string largestEven(string s) {
        int n = s.length();
        int last_one = s[n-1]-'0';
        if(last_one %2 ==0) return s;
        int j=n-1;
        while(j>=0 && (s[j]-'0')%2!=0){
            s.pop_back();
            j--;
        }
        return s;
    }
};