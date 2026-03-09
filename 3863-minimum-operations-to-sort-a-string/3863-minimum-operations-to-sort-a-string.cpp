class Solution {
public:
    int minOperations(string s) {
        string t = s;
        int n = s.length();
        sort(begin(t),end(t));
        if(s==t) return 0;
        if(s.length() == 2) return -1;
        if(s[0]==t[0] || s[n-1]==t[n-1]) return 1;
        string s1 = s;
        sort(s1.begin() , s1.begin() + n-1); // [0 to second last];
        sort(s1.begin() + 1 , s1.end()); // [1 to last];
        string s2 = s;
        sort(s2.begin()+1,s2.end()); // pehle yehh ab ;
        sort(s2.begin() , s2.begin() + n-1);
        if(s1==t || s2==t) return 2;
        return 3;

    }
};