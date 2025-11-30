class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char>st;
        for(char ch : s){
            st.insert(ch);
        }
        return st.size();
    }
};