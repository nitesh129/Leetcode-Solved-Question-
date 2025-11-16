class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.length();
        int counta=0 , countb=0;
        for(char c : s){
            if(c=='a') counta++;
            else countb++;
        }
        return abs(counta-countb);
    }
};