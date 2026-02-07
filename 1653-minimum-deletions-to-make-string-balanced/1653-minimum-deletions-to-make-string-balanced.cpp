class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int ans =0;
        for(char ch : s){
            if(!st.empty() && (st.top() == 'b' && ch == 'a')){
                st.pop();
                ans++;
            }
            else st.push(ch);
        }
        return ans;
    }
};